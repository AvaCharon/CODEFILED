# JS第二课

## 与用户交互

### alert
```
alert("Hello");
```
弹出的这个带有信息的小窗口被称为 模态窗。“modal” 意味着用户不能与页面的其他部分（例如点击其他按钮等）进行交互，直到他们处理完窗口。在上面示例这种情况下 —— 直到用户点击“确定”按钮。

### prompt
```
result = prompt(title, [default]);//[]内的参数是可选的
```
访问者可以在提示输入栏中输入一些内容，然后按“确定”键。然后我们在 result 中获取该文本。或者他们可以按取消键或按 Esc 键取消输入，然后我们得到 null 作为 result。

prompt 将返回用户在 input 框内输入的文本，如果用户取消了输入，则返回 null。

例如：
```
let name = prompt("What is your name?", "");
alert(name);
```
### confirm
```
result = confirm(question);
```
confirm 函数显示一个带有 question 以及确定和取消两个按钮的模态窗口。

点击确定返回 true，点击取消返回 false。
```
let hasStudied = confirm("Have you studied today?");
alert( hasStudied ); // 如果“确定”按钮被按下，则显示 true
```

### 总结
这些方法都是模态的：它们暂停脚本的执行，并且不允许用户与该页面的其余部分进行交互，直到窗口被解除。

上述所有方法共有两个限制：

* 模态窗口的确切位置由浏览器决定。通常在页面中心。
* 窗口的确切外观也取决于浏览器。我们不能修改它。

## 函数
在 JavaScript 中，函数不是“神奇的语言结构”，而是一种特殊的值。

* 函数声明：

    在函数声明被定义之前，它就可以被调用。
    例如，一个全局函数声明对整个脚本来说都是可见的，无论它被写在这个脚本的哪个位置。
```
function sayHi() {
  alert( "Hello" );
}
```
* 函数表达式：

    函数表达式是在代码执行到达时被创建，并且仅从那一刻起可用。
```
let sayHi = function() {
  alert( "Hello" );
};
```
请注意，function 关键字后面没有函数名。函数表达式允许省略函数名。

这里我们立即将它赋值给变量，所以上面的两个代码示例的含义是一样的：“创建一个函数并将其放入变量 sayHi 中”。
```
function sayHi() {
  alert( "Hello" );
}
alert( sayHi ); // 显示函数代码
```

* 箭头函数
  
    创建函数还有另外一种非常简单的语法，并且这种方法通常比函数表达式更好。
  
```
let sum = (a, b) => a + b;

/* 这个箭头函数是下面这个函数的更短的版本：
let sum = function(a, b) {
  return a + b;
};
*/

/* 箭头函数也可以这样：
let sum = (a, b) => {  // 花括号表示开始一个多行函数
  let result = a + b;
  return result; // 如果我们使用了花括号，那么我们需要一个显式的 “return”
};
*/

alert( sum(1, 2) ); // 3
```