package RandomPython;

import javax.swing.JOptionPane;

import TrackmanMethods;
public class Trackman {
    static double[] holes;
    static int[] par;
	showGraph(){
		
	}
    public static void main(String[] args) {
        int numHoles;
        TrackmanMethods player1 = new TrackmanMethods();
        String temp;
        double shotDistance = 0;
        double fromHole = 0;
        double chipDistance = 0;
        double puttDistance = 0;
        int strokeCount = 0;
        int holeStrokeCount = 0;
        
        //welcome
        JOptionPane.showMessageDialog(null, "Hello, welcome to Trackman!");
        player1.gameProperties();
        do {
        	temp = JOptionPane.showInputDialog("Would you like to play 9 holes or 18 holes?");
        	numHoles = Integer.parseInt(temp);
        } while(numHoles != 9 && numHoles != 18);
        holes = new double[numHoles];
        JOptionPane.showMessageDialog(null, "You will be playing " + numHoles + " holes today.");
        
        //create holes
        for(int i = 0; i < holes.length; i++) {
            holes[i] = (int)((Math.random() * 3) + 3);
        }
        for(int i = 0; i < holes.length; i++) {
            if(holes[i] == 3) {
                holes[i] = (Math.random() * 50) + 150;
            }
            else if (holes[i] == 4) {
                holes[i] = (Math.random() * 100) + 300;
            }
            else if (holes[i] == 5) {
                holes[i] = (Math.random() * 100) + 500;
            }
        }
        
        //hole introduction/actually playing
        int coursePar = 0;
        for(int i = 0; i < holes.length; i++) {
        	fromHole = holes[i];
        	holeStrokeCount = 0;
        	if(holes[i] < 200 && holes[i] >= 150) {
        		JOptionPane.showMessageDialog(null, "Hole " + (i + 1) + ": Par 3, " + holes[i] + " yards");
        		coursePar += 3;
        	}
        	else if (holes[i] < 400 && holes[i] >= 300) {
        		JOptionPane.showMessageDialog(null, "Hole " + (i + 1) + ": Par 4, " + holes[i] + " yards");
        		coursePar += 4;
        	}
        	else {
        		JOptionPane.showMessageDialog(null, "Hole " + (i + 1) + ": Par 5, " + holes[i] + " yards");
        		coursePar += 5;
        	}
        	while(fromHole > 50) {
        		JOptionPane.showMessageDialog(null, "You have " + fromHole + " yards to the pin.");
        		shotDistance = player1.shotDistance();
        		fromHole = Math.abs(fromHole - shotDistance);
        		JOptionPane.showMessageDialog(null, "Your shot went " + shotDistance + " yards.");
        		strokeCount++;
        		holeStrokeCount++;
        	}
        	while(fromHole <= 50) {
        		if (fromHole <= 20) {
        			break;
        		}
        		JOptionPane.showMessageDialog(null, "You have " + fromHole + " yards to the pin.");
        		JOptionPane.showMessageDialog(null, "You are currently chipping.");
        		chipDistance = player1.chipping();
        		fromHole = Math.abs(fromHole - chipDistance);
        		JOptionPane.showMessageDialog(null, "Your chip went " + chipDistance + " yards.");
        		strokeCount++;
        		holeStrokeCount++;
        	}
        	while(fromHole <= 20) {
        		if(fromHole <= 3) {
        			JOptionPane.showMessageDialog(null, "Auto finishing hole...");
        			fromHole = 0;
        			strokeCount++;
        			holeStrokeCount++;
        			JOptionPane.showMessageDialog(null, "It took you " + holeStrokeCount + " shots to complete this hole.");
        			break;
        		}
        		JOptionPane.showMessageDialog(null, "You have " + fromHole + " yards to the pin.");
        		puttDistance = player1.putting();
        		fromHole = Math.abs(fromHole - puttDistance);
        		JOptionPane.showMessageDialog(null, "Your putt went " + puttDistance + " yards.");
        		strokeCount++;
        		holeStrokeCount++;
        	}	
        }
        
        //displaying results
        JOptionPane.showMessageDialog(null, "Congratulations, here are your results.");
        JOptionPane.showMessageDialog(null, "You played " + numHoles + " holes.");
        JOptionPane.showMessageDialog(null, "Which took you " + strokeCount + " strokes to complete.");
        if(strokeCount < coursePar) {
        	JOptionPane.showMessageDialog(null, "The course par was " + coursePar + ", so you shot " + (coursePar - strokeCount) + "under par.");
        }
        else if (strokeCount == coursePar) {
        	JOptionPane.showMessageDialog(null, "The course par was " + coursePar + ", so you shot even par.");
        }
        else {
        	JOptionPane.showMessageDialog(null, "The course par was " + coursePar + ", so you shot " + (strokeCount - coursePar) + "over par.");
        }
        JOptionPane.showMessageDialog(null, "Thanks for playing Trackman!");
        
    }
}

