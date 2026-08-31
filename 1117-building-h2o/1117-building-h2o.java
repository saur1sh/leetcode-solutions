class H2O {

    private Semaphore oGate = new Semaphore(1);
    private Semaphore hGate = new Semaphore(2);
    private Semaphore hQueue = new Semaphore(0);
    private Semaphore oQueue = new Semaphore(0);

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {

        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        hGate.acquire();
        hQueue.release();
        oQueue.acquire();

        releaseHydrogen.run();
        hGate.release();

    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {

        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        oGate.acquire();
        hQueue.acquire();
        hQueue.acquire();
        oQueue.release(2);

        releaseOxygen.run();
        oGate.release();
    }
}