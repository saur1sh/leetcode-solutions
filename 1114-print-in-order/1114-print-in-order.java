class Foo {

    private int step = 1;
    private Object lock = new Object();

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized (lock) {
            printFirst.run();
            step = 2;
            lock.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized (lock) {
            while (step != 2) {
                lock.wait();
            }
            printSecond.run();
            step = 3;
            lock.notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized (lock) {
            while (step != 3) {
                lock.wait();
            }
            printThird.run();
        }
    }
}