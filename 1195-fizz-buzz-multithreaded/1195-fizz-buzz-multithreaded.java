class FizzBuzz {
    private int n;
    private State state = State.NUM;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 == 0) {
                continue;
            }
            while (state != State.FIZZ) {
                wait();
            }
            printFizz.run();
            state = state.NUM;
            notifyAll();
        }
    }

    // printBuzz.run() outputs "buzz".
    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 == 0) {
                continue;
            }
            while (state != State.BUZZ) {
                wait();
            }
            printBuzz.run();
            state = state.NUM;
            notifyAll();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i += 15) {
            while (state != State.FIZZBUZZ) {
                wait();
            }
            printFizzBuzz.run();
            state = state.NUM;
            notifyAll();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            while (state != State.NUM) {
                wait();
            }
            if (i % 3 == 0 && i % 5 == 0) {
                state = state.FIZZBUZZ;
            } else if (i % 3 == 0) {
                state = state.FIZZ;
            } else if (i % 5 == 0) {
                state = state.BUZZ;
            } else {
                printNumber.accept(i);
            }
            notifyAll();
        }
    }
}

enum State {
    FIZZ, BUZZ, FIZZBUZZ, NUM
}
