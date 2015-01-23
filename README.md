## Strange Behavior is go's os.GetEnv

The gist of the question is: how should go's os.GenEnv behave when an Env Var is not set vs. set to "". Right now, if the variable is absent, GetEnv returns "" -- the same as it does for if a variable is set to "". Other languges throw an error at this stage or at least differentiate between the two cases.

To investigate I created programs to check the behavior in both C and Go. Python, Node, Haskell all throw errors for unset variables. C will return (null) for an unset and "" for Env Variables set to "".

### Results

FOO and BAR are both unset:

```
bash-3.2$ echo $FOO

bash-3.2$ echo $BAR

bash-3.2$ ./checkEnvs-c
FOO is: (null)           0x0
BAR is: (null)           0x0
 FOO ==  BAR -> True
bash-3.2$ ./checkEnvs-go
FOO is:                  0x20818a220
BAR is:                  0x20818a230
 FOO ==  BAR -> True
```

FOO is set to "":

```
bash-3.2$ export FOO=""
bash-3.2$ ./checkEnvs-c
FOO is:                  0x7fff567b2b85
BAR is: (null)           0x0
 FOO ==  BAR -> False
bash-3.2$ ./checkEnvs-go
FOO is:                  0x20818a220
BAR is:                  0x20818a230
 FOO ==  BAR -> True
```

