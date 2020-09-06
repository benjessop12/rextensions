Some use(ful/less) c extensions for ruby objects.

Compile the c library then load for usage
```
ruby extconf.rb
make
irb -Ilib -rruby_extensions
```

## Fixnum functions

Is number a fibonacci number?
```
377.fib?
=> true
378.fib?
=> false
```

## Array functions
Reverse sort
```
[0, 1, 2, 4, 3].sort_r!
=> [4, 3, 2, 1, 0]
```

Consecutive values
```
[0, 1, 2, 4, 3].consec
=> [[0, 1, 2]]
[0, 1, 2, 3, 4].consec
=> [[0, 1, 2, 3, 4]]
[0, 1, 2, 3, 3].consec
=> [[0, 1, 2, 3]]
[1, 2, 3, 5, 6, 7].consec
=> [[1, 2, 3],[5, 6, 7]]
```

Squaring values
```
[0, 1, 2, 3, 4].square
=> [0, 1, 4, 9, 16]
[0, 1, 2, 3, 4, "5"].square
=> [0, 1, 4, 9, 16, 25]
```

Median by position
```
[1, 2, 3].median_p
=> 2
[1, 2, 3, 4, 9].median_p
=> 3
[1, 2, 3, 4].median_p
=> 2
```
