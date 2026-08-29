class FooBar {
    private int n;

    private volatile int state = 0;
    private Object lock = new Object();

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {

            // printFoo.run() outputs "foo". Do not change or remove this line.
            synchronized (lock) {
                while (state != 0) {
                    lock.wait();
                }
                printFoo.run();
                state = 1;
                lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {

            // printBar.run() outputs "bar". Do not change or remove this line.
            synchronized (lock) {
                while (state != 1) {
                    lock.wait();
                }
                printBar.run();
                state = 0;
                lock.notifyAll();
            }
        }
    }
}