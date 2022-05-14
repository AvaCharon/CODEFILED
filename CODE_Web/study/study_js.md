## 空值合并运算符 '??'

?? 的常见使用场景是提供默认值。

例如，在这里，如果 user 的值不为 null/undefined 则显示 user，否则显示 匿名：
```
let user;
alert(user ?? "匿名"); // 匿名（user 未定义）
```

```
let user = "John";
alert(user ?? "匿名"); // John（user 已定义）
```

## 可选链'?.'

如果可选链 ?. 前面的值为 undefined 或者 null，它会停止运算并返回 undefined。例如 value?.prop：
如果 value 存在，则结果与 value.prop 相同，
否则（当 value 为 undefined/null 时）则返回 undefined。
```
//其它变体：?.()，?.[]

let userAdmin = {
  admin() {
    alert("I am admin");
  }
};
let userGuest = {};
userAdmin.admin?.(); // I am admin
userGuest.admin?.(); // 啥都没发生（没有这样的方法）

let key = "firstName";
let user1 = {
  firstName: "John"
};
let user2 = null;
alert( user1?.[key] ); // John
alert( user2?.[key] ); // undefined
```