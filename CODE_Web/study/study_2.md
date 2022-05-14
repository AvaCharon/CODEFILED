# JS第三课

## 对象

### 创建对象
* 属性
  
用下面两种语法中的任一种来创建一个空的对象

```
let user = new Object(); // “构造函数” 的语法
let user = {};  // “字面量” 的语法

let user = {     // 一个对象
  name: "John",  // 键 "name"，值 "John"
  age: 30        // 键 "age"，值 30
  "likes birds": true  // 多词属性名必须加引号
};
```
* 方法
    ```
    // 这些对象作用一样
    user = {
    sayHi: function() {
        alert("Hello");
    }
    };

    // 方法简写看起来更好，对吧？
    let user = {
    sayHi() { // 与 "sayHi: function(){...}" 一样
        alert("Hello");
    }
    };
    ```
Tip 箭头函数没有this
### 方括号

```
let user = {};

// 设置
user["likes birds"] = true;

// 读取
alert(user["likes birds"]); // true

// 删除
delete user["likes birds"];
```
方括号同样提供了一种可以通过任意表达式来获取属性名的方法 —— 跟语义上的字符串不同 —— 比如像类似于下面的变量：
```
let key = "likes birds";

// 跟 user["likes birds"] = true; 一样
user[key] = true;
```
当创建一个对象时，我们可以在对象字面量中使用方括号。这叫做 计算属性。例如：
```
let fruit = prompt("Which fruit to buy?", "apple");

let bag = {
  [fruit]: 5, // 属性名是从 fruit 变量中得到的
};

alert( bag.apple ); // 5 如果 fruit="apple"
```