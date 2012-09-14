program zoj2745;

{ Error: Identifier not found "max" }
{ Error: Identifier not found "min" }
uses math;

{
function max(a, b: integer): integer
begin
    if a >= b then
        max = a
    else
        max = b;
end;
}
var
    i, j, k, l, t: integer;
    {   length  maxdiff max0-1  min0-1}
    dp: array[0..62, 0..5, -5..5, -5..5] of int64;
    ans: array[1..62, 0..5] of int64;
begin
    for i := 0 to 62 do
        for j := 0 to 5 do
            for k := -5 to 5 do
                for l := -5 to 5 do
                    dp[i, j, k, l] := 0;
    dp[0, 0, 0, 0] := 1;
    for i := 0 to 61 do
        for j := 0 to 5 do
            for k := -5 to 5 do
                for l := -5 to 5 do
                begin
                    if dp[i, j, k, l] = 0 then
                        continue;
                    {add 0}
                    if k < 5 then
                    begin
                        t := max(1, k + 1);
                        inc(dp[i + 1, max(j, max(t, abs(l + 1))), t, l + 1], dp[i, j, k, l]);
                    end;
                    {add 1}
                    if l > -5 then
                    begin
                        t := min(-1, l - 1);
                        inc(dp[i + 1, max(j, max(-t, abs(k - 1))), k - 1, t], dp[i, j, k, l]);
                    end;
                end;
    for i := 1 to 62 do
    begin
        ans[i, 0] := 0;
        for j := 1 to 5 do
        begin
            ans[i, j] := ans[i, j - 1];
            for k := -5 to 5 do
                for l := -5 to 5 do
                    inc(ans[i, j], dp[i, j, k, l]);
        end;
    end;

    while not eof(input) do
    begin
        readln(i, j);
        writeln(ans[i, j]);
    end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
3021868 2008-08-04 22:26:04 Accepted 2745 GPC 00:00.00 3128K Re:ReJudge
}

{ 2012-09-07 03:44:38 | Compilation Error | 2745 | FPC | 0 | 0 | watashi | Source }

{ Wrong Answer: %s/longint/int64/g }

{ 2012-09-07 15:45:42 | Accepted | 2745 | FPC | 0 | 492 | watashi | Source }
