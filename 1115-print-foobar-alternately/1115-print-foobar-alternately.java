class FooBar {
    private int n;

    private volatile int state = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {

            // printFoo.run() outputs "foo". Do not change or remove this line.
            while (state != 0) {
                Thread.onSpinWait();
            }
            printFoo.run();
            state = 1;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {

            // printBar.run() outputs "bar". Do not change or remove this line.
            while (state != 1) {
                Thread.onSpinWait();
            }
            printBar.run();
            state = 0;
        }
    }
}