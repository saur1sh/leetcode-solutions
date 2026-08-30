class H2O {

    private int h = 0;

    public H2O() {

    }

    public synchronized void hydrogen(Runnable releaseHydrogen) throws InterruptedException {

        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        while (h == 2) {
            wait();
        }
        h++;
        releaseHydrogen.run();
        notifyAll();
    }

    public synchronized void oxygen(Runnable releaseOxygen) throws InterruptedException {

        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        while (h < 2) {
            wait();
        }
        h -= 2;
        releaseOxygen.run();
        notifyAll();
    }
}