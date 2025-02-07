// Value categories

// An L-Value (left value) is an expression that evalutes to an identifble entity
// i.e. x = 5, now x (a varibale, that can be identifed) has a value

// An R-Value (right value) is an expression with no idenifiable entity
// i.e. add(5+5), both the return value and the args are rvalues
// since they are not stored anywhere (temparory values, not idenifiiable entities)

// l-values can be implicity converted to r-values
// so x = y can work even though y is an l-value
// and the operator= expects a rvalue

// l-value references
// i.e. int& x
// basically just pointer syntax but with an &
// (horrible design choice btw)
