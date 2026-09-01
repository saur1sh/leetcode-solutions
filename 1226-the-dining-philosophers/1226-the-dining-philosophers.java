class DiningPhilosophers {
    private Semaphore[] forks = new Semaphore[5];
    private Semaphore bouncer;

    public DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            forks[i] = new Semaphore(1);
        }
        this.bouncer = new Semaphore(4);
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
            Runnable pickLeftFork,
            Runnable pickRightFork,
            Runnable eat,
            Runnable putLeftFork,
            Runnable putRightFork) throws InterruptedException {
        bouncer.acquire();
        int leftFork = philosopher;
        int rightFork = (philosopher + 4) % 5;
        forks[leftFork].acquire();
        pickLeftFork.run();
        forks[rightFork].acquire();
        pickRightFork.run();
        eat.run();
        putRightFork.run();
        forks[rightFork].release();
        putLeftFork.run();
        forks[leftFork].release();
        bouncer.release();
    }
}