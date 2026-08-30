class ZeroEvenOdd {
    private int n;
    private volatile int state = 0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            while (state != 0) {
                Thread.onSpinWait();
            }
            printNumber.accept(0);
            state = (i % 2 == 0) ? 2 : 1;
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            while (state != 2) {
                Thread.onSpinWait();
            }
            printNumber.accept(i);
            state = 0;
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            while (state != 1) {
                Thread.onSpinWait();
            }
            printNumber.accept(i);
            state = 0;
        }
    }
}