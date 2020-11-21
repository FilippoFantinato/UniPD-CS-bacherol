public class Fibonacci
{
    static int fibonacci(int n)
    {
        return switch(n) {
            case 0 -> 0;
            case 1 -> 1;
            default -> fibonacci(n-1) + fibonacci(n-2);
        };
    }
}
