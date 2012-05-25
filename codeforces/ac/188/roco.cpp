/*
Roco Programming Language Interpreter version 20071014

Copyright (c) 2007 Lode Vandevenne
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
  * Neither the name of Lode Vandevenne nor the names of his contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
This is an interpreter for the roco programming language.

When it encounters a parser or runtime error, it'll display a numbered error message. These numbers have nothing
to do with the specification of roco. Look in the source code here to find out what number means what.
*/

/*
  g++ *.cpp
  g++ *.cpp -W -Wall -Wextra -pedantic -ansi -O3
  g++ *.cpp -W -Wall -Wextra -pedantic -ansi
*/

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////
//Helper Functions
////////////////////////////////////////////////////////////////////////////////

template<typename T>
void loadFile(T& buffer, const std::string& filename) //designed for loading files from hard disk in an std::vector
{
  std::ifstream file(filename.c_str(), std::ios::in|std::ios::binary|std::ios::ate);

  //get filesize
  std::streamsize size = 0;
  if(file.seekg(0, std::ios::end).good()) size = file.tellg();
  if(file.seekg(0, std::ios::beg).good()) size -= file.tellg();

  //read contents of the file into the vector
  buffer.resize(size_t(size));
  if(size > 0) file.read((char*)(&buffer[0]), size);
}

//write given buffer to the file, overwriting the file, it doesn't append to it.
template<typename T>
void saveFile(const T& buffer, const std::string& filename)
{
  std::ofstream file(filename.c_str(), std::ios::out|std::ios::binary);
  file.write(buffer.empty() ? 0 : (char*)&buffer[0], std::streamsize(buffer.size()));
}

bool isWhiteSpace(char c)
{
  return c < 33; //I consider everything with the ascii code of a space and lower to be whitespace
}

bool isDigit(char c)
{
  return c >= '0' && c <= '9';
}

void skipWhiteSpace(const std::string& in, size_t& pos, size_t end)
{
  while(pos < end && isWhiteSpace(in[pos])) pos++;
}

void skipWhiteSpaceAndComments(const std::string& in, size_t& pos, size_t end)
{
  while(pos < end)
  {
    if(isWhiteSpace(in[pos]))
    {
      pos++;
      continue;
    }
    else if(in[pos] == '/' && pos + 1 < end && in[pos + 1] == '*')
    {
      int nest = 0;
      pos += 2;
      while(pos < end)
      {
        if(in[pos] == '/' && pos + 1 < end && in[pos + 1] == '*')
        {
          nest++;
          pos += 2;
        }
        if(in[pos] == '*' && pos + 1 < end && in[pos + 1] == '/')
        {
          pos += 2;
          if(nest == 0) break; //comment finished
          nest--;
        }
        else pos++;
      }
    }
    else break;
  }
}

int parseInteger(const std::string& s, size_t& pos, size_t end)
{
  if(pos >= end) return 0;
  
  std::string str;
  std::stringstream ss;
  int result;
  
  while(pos < end && (isDigit(s[pos]) || s[pos] == '-')) str += s[pos++];
  ss.str(str);
  ss >> result;
  
  return result;
}

void parseNonWhiteSpace(std::string& out, const std::string& in, size_t& pos, size_t end)
{
  out.clear();
  while(pos < end && !isWhiteSpace(in[pos]))
  {
    out.push_back(in[pos]);
    pos++;
  }
}

bool isIdentifier(char c)
{
  return isDigit(c) || (c == '_') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void parseIdentifier(std::string& out, const std::string& in, size_t& pos, size_t end)
{
  out.clear();
  while(pos < end && isIdentifier(in[pos]))
  {
    out.push_back(in[pos]);
    pos++;
  }
}

int getLine(const std::string& text, size_t pos)
{
  /*
  returns on which line of the text the given pos is
  */
  int line = 1;
  for(size_t i = 0; i < pos; i++)
  {
    if(text[i] == 10) line++;
  }
  return line;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//Roco
////////////////////////////////////////////////////////////////////////////////

class Coroutine;

class Parameter
{
  public:
  
  Parameter()
  {
    error = 0;
  }
  
  enum Type //usable in the same way to represent values, variables or coroutines
  {
    LITERAL, //the parameter is literally this number
    VARIABLE, //the parameter is the variable with this number
    POINTER //the parameter is the pointer with this number
  } type;
  
  long value;
  
  long& at(std::vector<long>& v, long index)
  {
    if(index >= (long)(v.size())) v.resize(index + 1);
    return v[index];
  }
  
  long get()
  {
    try
    {
      if(type == LITERAL) return value;
      else if(type == VARIABLE) return at(*variables, value);
      else return at(*variables, at(*variables, value));
    }
    catch(...)
    {
      error = 1;
      return 0;
    }
  }
  
  void assign(long i)
  {
    if(type == LITERAL)
    {
      error = 2;
      return;
    }
    
    try
    {
      if(type == VARIABLE) at(*variables, value) = i;
      else if(type == POINTER) at(*variables, at(*variables, value)) = i;
    }
    catch(...)
    {
      error = 3;
    }
  }
  
  void setLiteral(long value)
  {
    type = LITERAL;
    this->value = value;
  }
  
  void setVariable(long value)
  {
    type = VARIABLE;
    this->value = value;
  }
  
  void setPointer(long value)
  {
    type = POINTER;
    this->value = value;
  }
  
  bool hasError() { return error != 0; }
  int getError() { return error; }
  
  void setVariables(std::vector<long>* variables)
  {
    this->variables = variables;
  }
  
  private:
  int error;
  std::vector<long>* variables;
};

class Instruction
{
  public:
  enum Type
  {
    YI, //yield
    CA, //call
    AC, //return
    IF, //if
    SET, //set equal to
    EQ, //equals
    NEQ, //not-equals
    GT, //greater than
    LT, //lesser than
    INC, //increment
    DEC, //decrement
    ADD, //add
    SUB, //subtract
    MUL, //multiply
    DIV, //divide
    MOD, //modulo division
    AND, //and
    OR, //or
    XOR, //xor
    NOT, //not
    COUT, //output a character
    CIN, //input a character
    IOUT, //output an integer
    IIN //input an integer
  } type;
  
  Parameter op[1]; //output parameter
  Parameter ip[2]; //input parameters
  
  int execute(std::vector<Coroutine*>& coroutines, long& current_coroutine, std::vector<long>& coroutine_stack, std::vector<long>& variables);
  
  int parse(const std::string& code, size_t& pos, size_t end, const std::string& operation);
};

class Coroutine //a node from the roco tree, which is in fact a coroutine
{
  private:
  
  std::map<std::string, size_t> vars; //the variables while being parsed (unused once the program is running); size_t is index in global variables vector
  std::map<std::string, size_t> co; //coroutines inside the scope of this coroutine while being parsed (unused once the program is running); size_t is index in global coroutines vector
  
  std::vector<Instruction> instructions;
  
  size_t ip; //the instruction pointer (counter)
  
  Coroutine* parent;
  
  bool forward_declared;
  
  public:
  
  void setForwardDeclared(bool set)
  {
    forward_declared = set;
  }
  
  bool isForwardDeclared() const
  {
    return forward_declared;
  }
  
  void jumpIp(size_t amount)
  {
    if(instructions.empty()) return;
    ip += amount;
    if(ip >= instructions.size()) ip %= instructions.size();
  }
  
  int executeCurrentInstruction(std::vector<Coroutine*>& coroutines, long& current_coroutine, std::vector<long>& coroutine_stack, std::vector<long>& variables)
  {
    if(instructions.empty()) return 0; //nothing to execute, you're stuck in infinite loop in this coroutine :)
    int error = instructions[ip].execute(coroutines, current_coroutine, coroutine_stack, variables);
    jumpIp(1);
    return error;
  }
  
  Coroutine* getParent()
  {
    return parent;
  }
  
  void setParent(Coroutine* parent)
  {
    this->parent = parent;
  }
  
  Coroutine()
  {
    parent = 0;
    ip = 0;
    forward_declared = false;
  }
  
  long getCoroutine(const std::string& identifier) //will apply scope identifier lookup rules; returns global index of the coroutine, or -1 if none
  {
    if(co.find(identifier) != co.end()) return co[identifier];
    if(parent != 0) return parent->getCoroutine(identifier);
    else if(identifier == "ro") return 0; //the root routine
    else return -1; //nothing found at all
  }
  
  int parse(const std::string& text, size_t& pos, size_t end, std::vector<Coroutine*>& coroutines)
  {
    bool done = false;
    while(!done)
    {
      std::string name;
      skipWhiteSpaceAndComments(text, pos, end);
      
      if(pos >= end || text[pos] == '}')
      {
        pos++;
        done = true; //end of routine
        continue;
      }
      
      parseIdentifier(name, text, pos, end);
      
      if(name == "yi" || name == "ca")
      {
        skipWhiteSpaceAndComments(text, pos, end);
        std::string co_id;
        parseIdentifier(co_id, text, pos, end);
        
        long co_index = getCoroutine(co_id);
        
        if(co_index < 0) return 12; //ERROR: invalid identifier
        
        instructions.resize(instructions.size() + 1);
        if(name == "yi") instructions.back().type = Instruction::YI;
        else if(name == "ca") instructions.back().type = Instruction::CA;
        instructions.back().ip[0].setLiteral(co_index);
      }
      else if(name == "ac")
      {
        instructions.resize(instructions.size() + 1);
        instructions.back().type = Instruction::AC;
      }
      else if(name == "co")
      {
        skipWhiteSpaceAndComments(text, pos, end);
        std::string co_id;
        parseIdentifier(co_id, text, pos, end);
        
        if(co_id == "ro") return 13; //ERROR: ro is the name of the root routine, do not overload it
        
        skipWhiteSpaceAndComments(text, pos, end);
        if(text[pos] == '{')
        {
          pos++;
          
          Coroutine* c;

          if(co.find(co_id) != co.end())
          {
            c = coroutines[co[co_id]];
            if(!c->isForwardDeclared()) return 14; //ERROR: coroutine defined twice (if negative, it was forward declared, which is ok)
            c->setForwardDeclared(false);
          }
          else
          {
            co[co_id] = coroutines.size();
            c = new Coroutine;
            coroutines.push_back(c);
          }

          c->setParent(this);
          int error = c->parse(text, pos, end, coroutines);
          if(error) return error; //ERROR while parsing the sub-coroutine
        }
        else if(text[pos] == ';') //forward declared coroutine
        {
          if(co.find(co_id) == co.end())
          {
            co[co_id] = coroutines.size();
            Coroutine* c = new Coroutine;
            coroutines.push_back(c);
            c->setForwardDeclared(true);
          }
          pos++;
          //if forward declared a second time, no action has to be taken...
        }
        else return 15; //ERROR: coroutine must start with { and use } at the end, or use ";" for forward declaration
      }
      else
      {
        instructions.resize(instructions.size() + 1);
        int error = instructions.back().parse(text, pos, end, name);
        if(error) return error; //ERROR while parsing instruction
      }
    }
    
    return 0;
  }
};


int Instruction::execute(std::vector<Coroutine*>& coroutines, long& current_coroutine, std::vector<long>& coroutine_stack, std::vector<long>& variables) //returns error value
{
  op[0].setVariables(&variables);
  ip[0].setVariables(&variables);
  ip[1].setVariables(&variables);

  switch(type)
  {
    case YI:
      current_coroutine = ip[0].get();
      break;
    case CA:
      coroutine_stack.push_back(current_coroutine);
      current_coroutine = ip[0].get();
      break;
    case AC:
      if(coroutine_stack.empty())
      {
        current_coroutine = -1;
      }
      else
      {
        current_coroutine = coroutine_stack.back();
        coroutine_stack.pop_back();
      }
      break;
    case IF:
      if(!ip[0].get()) coroutines[current_coroutine]->jumpIp(1);
      break;
    case SET:
      op[0].assign(ip[0].get());
      break;
    case EQ:
      op[0].assign(ip[0].get() == ip[1].get());
      break;
    case NEQ:
      op[0].assign(ip[0].get() != ip[1].get());
      break;
    case GT:
      op[0].assign(ip[0].get() > ip[1].get());
      break;
    case LT:
      op[0].assign(ip[0].get() < ip[1].get());
      break;
    case INC:
      op[0].assign(op[0].get() + 1);
      break;
    case DEC:
      op[0].assign(op[0].get() - 1);
      break;
    case ADD:
      op[0].assign(ip[0].get() + ip[1].get());
      break;
    case SUB:
      op[0].assign(ip[0].get() - ip[1].get());
      break;
    case MUL:
      op[0].assign(ip[0].get() * ip[1].get());
      break;
    case DIV:
      op[0].assign(ip[0].get() / ip[1].get());
      break;
    case MOD:
      op[0].assign(ip[0].get() % ip[1].get());
      break;
    case AND:
      op[0].assign(ip[0].get() & ip[1].get());
      break;
    case OR:
      op[0].assign(ip[0].get() | ip[1].get());
      break;
    case XOR:
      op[0].assign(ip[0].get() ^ ip[1].get());
      break;
    case NOT:
      op[0].assign(~ip[0].get());
      break;
    case COUT:
      std::cout << (char)(ip[0].get());
      break;
    case CIN:
      op[0].assign(std::cin.get());
      break;
    case IOUT:
      std::cout << ip[0].get();
      break;
    case IIN:
      int i;
      std::cin >> i;
      op[0].assign(i);
      break;
    default:
      return 5; //unexisting operation
  }
  
  if(op[0].hasError()) return op[0].getError();
  if(ip[0].hasError()) return ip[0].getError();
  if(ip[1].hasError()) return ip[1].getError();
  
  return 0;
}

int parseVariable(long& pointer, long& value, const std::string& code, size_t& pos, size_t end)
{
  skipWhiteSpaceAndComments(code, pos, end);
  if(pos >= end) return 6; //ERROR
  
  pointer = 0; //0=literal, 1=variable, 2=pointer
  
  if(code[pos] == '[')
  {
    pointer = 1;
    pos++;
    if(pos >= end) return 7; //ERROR
    if(code[pos] == '[')
    {
      pointer = 2;
      pos++;
      if(pos >= end) return 8; //ERROR
    }
  }
  
  if(!isDigit(code[pos]) && code[pos] != '-') return 9; //ERROR
  
  value = parseInteger(code, pos, end);
  
  if(pointer == 1)
  {
    if(pos >= end || code[pos] != ']') return 10; //ERROR
    pos++;
  }
  else if(pointer == 2)
  {
    if(pos >= end - 1 || code[pos] != ']' || code[pos + 1] != ']') return 11; //ERROR
    pos += 2;
  }
  
  return 0;
}

int Instruction::parse(const std::string& code, size_t& pos, size_t end, const std::string& operation)
{
  size_t numiparams = 0, numoparams = 0; //input and output parameters
  
  if(operation == "") return 20;
  else if(operation == "yi") return 21; //shouldn't be handled here, because it requires name of coroutine, which isn't handled here.
  else if(operation == "ca") return 21; //shouldn't be handled here, because it requires name of coroutine, which isn't handled here.
  else if(operation == "ac") return 21; //shouldn't be handled here
  else if(operation == "if")
  {
    type = IF;
    numiparams = 1;
  }
  else if(operation == "set")
  {
    type = SET;
    numoparams = 1;
    numiparams = 1;
  }
  else if(operation == "eq")
  {
    type = EQ;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "neq")
  {
    type = NEQ;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "gt")
  {
    type = GT;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "lt")
  {
    type = LT;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "inc")
  {
    type = INC;
    numoparams = 1;
    numiparams = 0;
  }
  else if(operation == "dec")
  {
    type = DEC;
    numoparams = 1;
    numiparams = 0;
  }
  else if(operation == "add")
  {
    type = ADD;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "sub")
  {
    type = SUB;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "mul")
  {
    type = MUL;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "div")
  {
    type = DIV;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "mod")
  {
    type = MOD;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "and")
  {
    type = AND;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "or")
  {
    type = OR;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "xor")
  {
    type = XOR;
    numoparams = 1;
    numiparams = 2;
  }
  else if(operation == "not")
  {
    type = NOT;
    numoparams = 1;
    numiparams = 1;
  }
  else if(operation == "cout")
  {
    type = COUT;
    numiparams = 1;
  }
  else if(operation == "cin")
  {
    type = CIN;
    numoparams = 1;
  }
  else if(operation == "iout")
  {
    type = IOUT;
    numiparams = 1;
  }
  else if(operation == "iin")
  {
    type = IIN;
    numoparams = 1;
  }
  else return 50; //ERROR: unexisting instruction
  
  for(size_t i = 0; i < numoparams; i++) //the output parameters always come before the input parameters
  {
    long pointer, value;
    int error = parseVariable(pointer, value, code, pos, end);
    if(error) return error; //ERROR
    op[i].value = value;
    if(pointer == 0) return 5; //ERROR: output variable may not be a literal
    else if(pointer == 1) op[i].type = Parameter::VARIABLE;
    else if(pointer == 2) op[i].type = Parameter::POINTER;
  }
  
  for(size_t i = 0; i < numiparams; i++)
  {
    long pointer, value;
    
    int error = parseVariable(pointer, value, code, pos, end);
    if(error) return error; //ERROR
    ip[i].value = value;
    if(pointer == 0) ip[i].type = Parameter::LITERAL;
    else if(pointer == 1) ip[i].type = Parameter::VARIABLE;
    else if(pointer == 2) ip[i].type = Parameter::POINTER;
  }
  
  return 0;
}

class Program
{
  private:
  //globals (the current program state)
  std::vector<long> variables; //the heap
  std::vector<Coroutine*> coroutines; //all coroutines
  long current_coroutine; //signed because -1 indicates the end
  std::vector<long> coroutine_stack; //stack used by call/return (ca/ac) system
  
  public:
  void clearCoroutines()
  {
    for(size_t i = 0; i < coroutines.size(); i++)
      delete coroutines[i];
    coroutines.clear();
  }
  
  ~Program()
  {
    clearCoroutines();
  }
  
 
  int parse(const std::string& text, int& errorline)
  {
    variables.clear();
    clearCoroutines();
    
    coroutines.resize(1); //the root routine has index 0
    coroutines.back() = new Coroutine;
    size_t pos = 0;
    int error = coroutines[0]->parse(text, pos, text.size(), coroutines);
    
    for(size_t i = 0; i < coroutines.size(); i++) if(coroutines[i]->isForwardDeclared()) error = 52; //ERROR: undefined coroutine
    
    if(error) errorline = getLine(text, pos);
    
    return error;
  }
  
  int run()
  {
    current_coroutine = 0;
    coroutine_stack.clear();
    
    while(current_coroutine >= 0)
    {
      int error = coroutines[current_coroutine]->executeCurrentInstruction(coroutines, current_coroutine, coroutine_stack, variables);
      if(error > 0) return error;
    }
    
    return 0;
  }
};

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    std::cout << "please provide a filename" << std::endl;
    return 0;
  }
  std::string text;
  std::string filename = argv[1];
  loadFile(text, filename);
  if(text.size() < 2)
  {
    std::cout << "The program is empty. This gives an infinite loop since there is no ac command. For convenience we stop here." << std::endl;
    return 0;
  }
  
  Program program;
  
  int error;
  
  //std::cout << "Parsing..." << std::endl;
  
  int errorline;
  error = program.parse(text, errorline);
  if(error)
  {
    std::cout << "Parsing error: " << error << " on line " << errorline << std::endl;
    return 0;
  }
  
  //std::cout << "Parsed..." << std::endl;
  
  error = program.run();
  if(error)
  {
    std::cout << "Runtime error: " << error << std::endl;
    return 0;
  }
  
  //std::cout << std::endl << "Done" << std::endl;
  
  std::cout << std::endl;
  
  return 0;
}
