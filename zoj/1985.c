/* //2 methods in summer2007 */

/* //hh::解的方法是构造一个堆栈，然后从左向由看矩形。如果当前看的矩形比堆栈顶的矩形大，则将当前看的矩形放进堆栈，记录index；否则的话，一直从堆栈中pop出矩形，根据index信息求解当前看的矩形和这个被pop出矩形之间所有矩形可以构成的大矩形的面积(index差乘以当前看的矩形的高度)。一直pop到堆栈顶的矩形小于当前看的矩形为止。 */
/* //每个矩形入栈一次，出栈一次，所以方法是O(N)的，用普通的O(N^2)的方法和归并法都会超时。 */
/* //flyee:求解的方法是构造一个堆栈，然后从上往下看字符串长度。如果当前的长度比堆栈顶的大，则将当前的长度放进堆栈，记录index；否则的话，一直从堆栈中pop，根据index信息求解当前的长度和这个被pop出的之间可以构成的最大面积(index差乘以当前看的长度)。一直pop到堆栈顶的长度小于当前的为止。最后再“加入”一个长度为0的字符串把栈抛空。 */

/* //太赞了~ */
/* //栈中的任一一个数有其左的数比自己要小，其右的数不小于自己~~然后可以保证每个tmp都是局部最大值 */
/* //堆栈中的数有目前没有比它小的数比自己晚出现，在两个堆栈间的数，比他们都大 */
#include <stdio.h>
#define isempty() (size==0)
#define clear() (size=0)
#define top() (stack[size-1])
#define topIndex() (index[size-1])
#define pop() (--size)
#define push(i,value) (index[size]=i,stack[size]=value,++size)
int stack[100001];
int index[100001];
int size;
int main()
{
    int i,j,x,t,n;
    long long tmp,ans;

    while(scanf("%d",&n)!=EOF && n){
        clear();
        push(-1,-1);
        ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&t);
            while((x=top())>t){
                pop();
                j=topIndex();
                tmp=(long long)x*(i-j-1);
                if(tmp>ans) ans=tmp;
            }
            push(i,t);
        }
        while((x=top())>-1){
            pop();
            j=topIndex();
            tmp=(long long)x*(n-j-1);
            if(tmp>ans) ans=tmp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2682867 2007-11-22 20:58:50 Accepted 1985 C 00:00.28 1176K わたし */


/* //Ice_AX::zan~左右扫一遍，统计(应该带路径压缩降低复杂度)dp */

#include <stdio.h>
#define MAXN 100000
int a[MAXN],l[MAXN],r[MAXN];
int _main()
{
    int i,n;
    long long tmp,ans;

    while(scanf("%d",&n)!=EOF && n){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            l[i]=i;
            while(l[i]&&a[i]<=a[l[i]-1]){/*路径压缩*/
                l[i]=l[l[i]-1];
            }
        }
        for(i=n-1;i>=0;i--){
            r[i]=i;
            while(r[i]<n-1&&a[i]<=a[r[i]+1]){/*路径压缩*/
                r[i]=r[r[i]+1];
            }
        }
        ans=0;
        for(i=0;i<n;i++){
            tmp=(long long)a[i]*(long long)(r[i]-l[i]+1);
            if(tmp>ans) ans=tmp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2682762 2007-11-22 18:56:48 Accepted 1985 C 00:00.29 1564K わたし */



/*
Problem H: Largest Rectangle in a Histogram

Note that the area of the largest rectangle may exceed the largest 32-bit integer. Due to the large numbers of rectangles, the naive O(n2) solution is too slow. Even though O(n*log(n)) or O(n) is required, there are several kinds of solutions to this problem. In the following, we will identify a histogram with the sequence of the heights of its rectangles.


1
Divide-and-conquer using order-statistic trees.
Initially, build a binary, node- and leaf-labeled tree that contains the histogram as its frontier, i.e., as its leaves from left to right. Mark each inner node with the minimum of the labels of its subtree. Note that such a tree is most efficiently stored in an array using the heap data structure, where the children of node i are located at positions i*2 and i*2+1, respectively. With such an order-statistic tree, the minimum element in a subhistogram (i.e., a subsegment of the sequence of heights) can be found in O(log(n)) steps by using the additional information in the inner nodes to avoid searching all leaves.
To calculate the maximum rectangle unter a subhistogram, we thus find the minimum height in that subhistogram, and divide it at just that place into two smaller histograms. The maximum rectangle is either completely in the left part, or completely in the right part, or it contains the rectangle with minimum height. The first two cases are solved recursively, while in the third case we know that the width of the maximum rectangle is the width of the whole subhistogram, since we chose the minimum height. Because every element serves exactly once as a place to divide, and we spend O(log(n)) for every division, the complexity of this algorithm is O(n*log(n)).
2
Linear search using order-statistic trees.
Initially, construct an order-statistic tree as just described. For every element, we find the largest rectangle that includes that element. The height of the rectangle is, of course, the value of the element. Use the order-statistic tree to efficiently find the nearest elements that have smaller heights, both to the left and to the right. The width, and therefore the area of the rectangle can thus be calculated in O(log(n)) steps, giving a total runtime of O(n*log(n)).
3
Sweeping line maintaining intervals.
Initially, sort the heights so they can be processed in non-increasing order. We sweep a horizontal line downwards through the histogram, maintaining a list of those intervals, where the line intersects the histogram. Actually, the intervals are maintained in an array with one entry for every element of the histogram in the following manner. At the element corresponding to the left end of an interval we store a pointer to the right end, and vice versa.
As a new element arrives during the sweeping process, this element forms a new interval, and, if there are adjacent intervals, these can be merged in constant time using our representation. The largest rectangle including this element, just as described in the previous algorithm, is available without further expense, since we can read its width from our representation. Actually, it is not quite the largest rectangle, because there may be further elements with equal heights adjacent to the current interval. Performing the sweep in a non-increasing order, however, guarantees that the largest rectangle will have been considered by the time the last element of a group having equal heights is examined. The complexity is dominated by the sorting phase, thus O(n*log(n)), although a radix sort is possible if the heights are bounded.
4
Linear search using a stack of incomplete subproblems
We process the elements in left-to-right order and maintain a stack of information about started but yet unfinished subhistograms. Whenever a new element arrives it is subjected to the following rules. If the stack is empty we open a new subproblem by pushing the element onto the stack. Otherwise we compare it to the element on top of the stack. If the new one is greater we again push it. If the new one is equal we skip it. In all these cases, we continue with the next new element.
If the new one is less, we finish the topmost subproblem by updating the maximum area w.r.t. the element at the top of the stack. Then, we discard the element at the top, and repeat the procedure keeping the current new element. This way, all subproblems are finished until the stack becomes empty, or its top element is less than or equal to the new element, leading to the actions described above. If all elements have been processed, and the stack is not yet empty, we finish the remaining subproblems by updating the maximum area w.r.t. to the elements at the top.
For the update w.r.t. an element, we find the largest rectangle that includes that element. Observe that an update of the maximum area is carried out for all elements except for those skipped. If an element is skipped, however, it has the same largest rectangle as the element on top of the stack at that time that will be updated later.
The height of the largest rectangle is, of course, the value of the element. At the time of the update, we know how far the largest rectangle extends to the right of the element, because then, for the first time, a new element with smaller height arrived. The information, how far the largest rectangle extends to the left of the element, is available if we store it on the stack, too.
We therefore revise the procedure described above. If a new element is pushed immediately, either because the stack is empty or it is greater than the top element of the stack, the largest rectangle containing it extends to the left no farther than the current element. If it is pushed after several elements have been popped off the stack, because it is less than these elements, the largest rectangle containing it extends to the left as far as that of the most recently popped element.
Every element is pushed and popped at most once and in every step of the procedure at least one element is pushed or popped. Since the amount of work for the decisions and the update is constant, the complexity of the algorithm is O(n) by amortized analysis.
5
Recursive search
For a recursive version of the algorithm just described, see the reference below. Indeed, if the recursion is eliminated the necessary stack is analogous to the explicit stack in the iterative version.
6
Rewrite System
The problem may be generalized by allowing histograms to be composed of rectangles with varying widths. Then, the stack used in the just described algorithms can be concatenated with the yet unprocessed part of the histogram into one list.
A three element window is moved over this list, starting at the left end. In every step, different actions are performed according to the relative heights of the three elements under inspection. The actions include updating the maximum, merging two of the three elements by taking the minimum of their heights and the sum of their widths, and sliding the window one element to the left or to the right. Rules are provided that specify the actions for each configuration.
Actually, the behaviour of the stack-based algorithm is simulated. The correctness of the rewrite system can be shown by proving an invariant about the maximum area of the histogram, observing that every configuration is matched by some rule, and giving a termination proof using a variant expression. Additionally, it can be proved that O(n) rewrite steps (each with a constant amount of work) are performed.
Judges' test data consisted of 32 hand-crafted test cases, 33 randomly generated test cases, and one test case with a histogram of width 99998.

Rating: Hard

Reference

Morgan, C.
Programming from Specifications
Chapter 21, pages 209-216, Prentice Hall International (UK) Limited, second edition, 1994
ISBN 0-13-123274-6
*/

// 2012-09-07 01:09:32 | Accepted | 1985 | C | 50 | 2112 | watashi | Source
