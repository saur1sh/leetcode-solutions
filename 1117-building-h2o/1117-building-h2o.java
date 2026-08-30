class H2O {

    private Semaphore o = new Semaphore(0);
    private Semaphore h = new Semaphore(2);

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {

        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        h.acquire();
        releaseHydrogen.run();
        if (h.availablePermits() == 0) {
            o.release();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {

        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        o.acquire();
        releaseOxygen.run();
        h.release(2);
    }
}