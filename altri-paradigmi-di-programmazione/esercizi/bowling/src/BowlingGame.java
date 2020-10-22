import java.util.ArrayList;
import java.util.List;

public class BowlingGame
{
	public static List<Integer> read(String score)
	{
		List<Integer> res = new ArrayList<>();

		for(int i = 0; i < score.length(); ++i)
		{
			if(score.charAt(i) == '-')
				res.add(0);
			else
				res.add(score.charAt(i) - '0');
		}

		return res;
	}
}
