import java.util.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Timer;
import java.util.regex.*;

public class main {
    public static void main(String[] args) {
        new Frame();
    }
}

class Frame extends JFrame {    
	Frame() {
		Panel panel = new Panel();
		this.add(panel);
		this.setTitle("gg");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setResizable(false);
		this.pack();
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
}
/*
this will contain like everything about the game

we will need a command prompt, an initializing thing,
and like everything else

*/

class Player {
    String name, house;
    int res[] = new int[3];
    double clock;
    Player(String n, String h, double t) {
        name = n;
        house = h;
        clock = t;
    }
    void change_resource(int i, int d) {
        res[i] += d;
    }
    void change_clock(double x) {
        clock += x / 1000;
    }
}

class Panel extends JPanel implements MouseListener{
	final Random random = new Random();
    final Pattern MOVE = Pattern.compile("([1-6][fhiFHI]([\\+-]?[0-9])){0,}[sS]?");
	Timer timer;

    final String[] RISING_DIE = {
        "Banish top card of any location",
        "Reveal and place top deck card anywhere",
        "Gain sovereign",
        "+Helium",
        "+Fleet",
        "+Influence"
    };

    boolean running = true;
    Player[] players;
    int N;
    int increment;

    //
    int turn = 0;
    String cmd;
    boolean paused = false;
	
	Panel() {
		setPreferredSize(new Dimension(1280, 720));
		setFocusable(true);
        //@TODO: find suitable color
		setBackground(new Color(51, 53, 55));
		setLayout(null);

        init_game();
	}

    void init_game() {
        Scanner sc = new Scanner("game.txt");
        N = sc.nextInt();
        int player_time = sc.nextInt();
        increment = sc.nextInt();
        players = new Player[N];

        ArrayList<String> HOUSES = new ArrayList<>();
        for (String x : new String[]{
            "APOLLO",
            "CERES",
            "DIANA",
            "JUPITER",
            "MARS",
            "MINERVA" }) { //peak indentation
            HOUSES.add(x);
        }

        int apolloi = -1;
        for (int i = 0; i < N; i++) {
            String n = sc.nextLine();
            String h = HOUSES.get(random.nextInt(0, HOUSES.size()));
            if (h.equals("APOLLO")) {
                apolloi = -2;
            }
            players[i] = new Player(n, h, player_time);
        }
        Collections.shuffle(Arrays.asList(players));
        if (apolloi == -2) {
            for (int i = 0; i < N; i++) {
                if (players[i].name.equals("APOLLO")) {
                    apolloi = i;
                    break;
                }
            }
            var tmp = players[apolloi].clone(); 
        }

    }

	void draw() {
        
	}


    //fairly certain we wont need these
	public void mouseReleased(MouseEvent e) {}
	public void mouseClicked(MouseEvent e) {}
	public void mousePressed(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
}
