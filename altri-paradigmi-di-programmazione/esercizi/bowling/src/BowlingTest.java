import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class BowlingTest {

    @Test
    void score()
    {
        assertEquals(180, Bowling.score("1/35XXX458/X3/X43"));
        assertEquals(104, Bowling.score("9-X8-9-9-9-9-9-9-X23"));
        assertEquals(300, Bowling.score("XXXXXXXXXXXX"));
        assertEquals(90, Bowling.score("9-9-9-9-9-9-9-9-9-9-"));
        assertEquals(80, Bowling.score("8-8-8-8-8-8-8-8-8-8-"));
        assertEquals(135, Bowling.score("238143XX5/--189/XXX"));
        assertEquals(150, Bowling.score("5/5/5/5/5/5/5/5/5/5/5/"));
    }
}