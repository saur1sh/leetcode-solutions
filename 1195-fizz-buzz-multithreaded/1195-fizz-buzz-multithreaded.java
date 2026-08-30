class FizzBuzz {
    private int n;
    private int i = 1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        while (i <= n) {
            if (i % 3 == 0 && i % 5 != 0) {
                printFizz.run();
                i++;
            } else {
                wait();
            }
            notifyAll();
        }
    }

    // printBuzz.run() outputs "buzz".
    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        while (i <= n) {
            if (i % 5 == 0 && i % 3 != 0) {
                printBuzz.run();
                i++;
            } else {
                wait();
            }
            notifyAll();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (i <= n) {
            if (i % 5 == 0 && i % 3 == 0) {
                printFizzBuzz.run();
                i++;
            } else {
                wait();
            }
            notifyAll();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        while (i <= n) {
            if (i % 3 != 0 && i % 5 != 0) {
                printNumber.accept(i);
                i++;
            } else {
                wait();
            }
            notifyAll();
        }
    }
}