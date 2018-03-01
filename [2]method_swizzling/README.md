>1.一个类维护着一张分发表(dispatch table)，用来解析运行时发来的消息；该表的每个入口是一个方法(Method)，其中的key就是选择器(SEL)，对应一个实现(IMP)，即一个指向底层c函数的指针。
>2.swizzle 一个方法就是改变类的分发表，使它在解析消息的时候，将一个选择器selector对应到别的实现，并且将该选择器对应的原始实现关联到新的选择器中。

>3.由于method swizzling会影响到全局的状态，因此最小化竞争条件的出现变得很重要，+load方法能够确保在类的初始化时候调用，这能够保证改变应用行为的一致性
保证不管有多少个线程，代码只会执行一次
避免冲突: 给category方法加前缀，确保不会跟其它依赖的代码产生冲突。
>4.在swizzling的过程中，xxx_viewWillAppear:已经被重新指向UIViewController 的原始实现-viewWillAppear:，但是如果我们在这个方法中调用viewWillAppear:则会导致无限循环
