class Foo {

    private volatile int step = 1;

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        step = 2;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (step != 2) {
            Thread.onSpinWait();
        }
        printSecond.run();
        step = 3;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (step != 3) {
            Thread.onSpinWait();
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}