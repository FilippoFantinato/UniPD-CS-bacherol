import org.jetbrains.annotations.NotNull;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

public class Bowling
{
    public static void main(String[] args)
    {

    }

    static int score(String s)
    {
        List<Integer> score = convertGame(s);
        int totalScore = evalScore(s, score);

        System.out.println("Score: " + totalScore);

        return totalScore;
    }

    /**
     * Converte la stringa game in una lista di Integer contenente i reali punteggi per ogni tiro,
     * senza bonus
     * @param game: stringa contenente la partita
     * @return La lista con tutti i punteggi numerici
     */
    private static List<Integer> convertGame(String game) {
        List<Integer> score = new LinkedList<>();

        score.add(symbolToIntDigit('0', game.charAt(0)));

        // Viene convertito ogni carattere tramite il metodo symbolToIntDigit e aggiunto alla lista
        // finale
        for (int i = 1; i < game.length(); ++i)
            score.add(symbolToIntDigit(game.charAt(i - 1), game.charAt(i)));

        return score;
    }

    /**
     * Calcola il punteggio della partita
     *
     * @param game: stringa contenente la partita
     * @param score: lista di Integer contenente i reali punteggi per ogni tiro, senza bonus
     * @return Il punteggio della partita
     */
    private static int evalScore(String game, List<Integer> score) {
        int totalScore = 0;

        // La variabile shots onta quanti tiri sono stati eseguiti.
        // Sapendo che il massimo di colpi che vengono utilizzati per il calcolo del punteggio sono 20,
        // se sono in numero maggiore significa che quelli in più sono stati utilizzati come bonus
        // per il calcolo dell'ultimo tiro, nel caso in cui si sia fatto uno spare o uno strike.
        // Perciò quei punti verranno sommati solo come bonus
        int shots = 0;

        // Si sia sulla stringa game e sia sulla lista con i relativi punteggi, così da sapere quando è
        // stato fatto
        // uno spare o uno strike e poterli gestire sommandogli il bonus adeguato
        for (int i = 0; i < game.length() && shots < 20; ++i) {
            switch (game.charAt(i)) {
                case '/' -> { // Se è stato fatto uno spare, allora il bonus sarà solo il tiro successivo
                    totalScore += score.get(i) + score.get(i + 1);
                }
                case 'X' -> { // Se è stato fatto uno strike, allora il bonus sarà la somma tra i due tiri
                    // successivi.
                    ++shots; // Viene incrementata ulteriormente la variabile shots, visto che non vengono
                    // fatti 2 colpi in questo caso
                    totalScore += score.get(i) + score.get(i + 1) + score.get(i + 2);
                }
                default -> { // Se non è un simbolo, allora si somma semplicemente senza alcun bonus
                    totalScore += score.get(i);
                }
            }

            // Viene incrementato il contatore di tiri
            ++shots;
        }

        return totalScore;
    }

    /**
     * Converte ogni carattere nel suo corrispondente valore numerico, inclusi anche i vari simboli
     *
     * @param prev: carattere precedente
     * @param current: carattere attuale
     * @return Valore numerico corrispondente al carattere contenuto in current
     */
    private static int symbolToIntDigit(char prev, char current) {
        return switch (current) {
            case 'X' -> 10;
            case '-' -> 0;
            case '/' -> 10 - (prev - '0');
            default -> current - '0';
        };
    }
}
