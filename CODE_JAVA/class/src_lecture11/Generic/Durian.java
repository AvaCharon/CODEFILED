package Generic;

// 定义类 Durian 时使用了泛型声明
class Durian<T> {
    // 使用T类型形参定义实例属性
    private T info;

    // 下面方法中使用T类型形参来定义构造函数
    public Durian(T info) {
        this.info = info;
    }

    public void setInfo(T info) {
        this.info = info;
    }

    public T getInfo() {
        return this.info;
    }

    // 静态泛型方法应该使用其他类型区分:
    public static <K> Durian<K>readyear(K info) {
        return new Durian<K>(info);
    }
}