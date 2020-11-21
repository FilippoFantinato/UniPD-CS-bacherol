import java.util.function.Predicate;
import java.util.stream.IntStream;

public class Perfect implements Predicate<CandidateNumber>
{
    @Override
    public boolean test(CandidateNumber candidateNumber)
    {
        return candidateNumber.number == candidateNumber.divisors.stream().reduce(0, Integer::sum);
    }
}
