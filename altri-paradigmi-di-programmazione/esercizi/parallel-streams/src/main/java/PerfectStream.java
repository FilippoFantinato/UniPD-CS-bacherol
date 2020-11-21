import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class PerfectStream
{
    private int n;

    PerfectStream(int n)
    {
        this.n = n;
    }

    void execute()
    {
        List<CandidateNumber> match =
                IntStream.range(1, n)
                        .boxed()
                        .parallel()
                        .map(new Divisors())
//                        .map((el) -> {
////                            System.out.println(el);
//                            return el;
//                        })
                        .filter(new Perfect())
                        .collect(Collectors.toList());

//        System.out.println(match);

        match.forEach(System.out::println);
    }
}
