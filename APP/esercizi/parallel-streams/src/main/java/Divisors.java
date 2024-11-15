import java.util.Collection;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Divisors implements Function<Integer, CandidateNumber>
{
    @Override
    public CandidateNumber apply(Integer n)
    {
        return new CandidateNumber(n,
                IntStream.range(1, /*Math.toIntExact(Math.round(Math.sqrt(Math.abs(n))))*/n)
                        .boxed()
                        .parallel()
                        .filter(i -> ((n % i) == 0) )
                        .collect(Collectors.toList()));
    }
}
