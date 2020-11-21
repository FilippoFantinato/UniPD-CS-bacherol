import java.util.List;

public class CandidateNumber
{
    int number;
    List<Integer> divisors;

    CandidateNumber(int number, List<Integer> divisors)
    {
        this.number = number;
        this.divisors = divisors;
    }

    @Override
    public String toString()
    {
        return "CandidateNumber{" +
                "number=" + number +
                ", divisors=" + divisors +
                '}';
    }
}
