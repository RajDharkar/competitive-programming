import javax.swing.*;
public class TrackmanMethods {
    public void gameProperties() {
        JOptionPane.showMessageDialog(null, "Now, you will learn your club distances and how the game will work.");
        JOptionPane.showMessageDialog(null, "You will be guessing two numbers per shot which will determine your shot.");
        JOptionPane.showMessageDialog(null, "For every integer you are off from the first auto-generated guess, you will gain or lose 0.25% distance from your shot.");
        JOptionPane.showMessageDialog(null, "If your first guess is low, your shot will be shorter, if it's high, your shot will be longer.");
        JOptionPane.showMessageDialog(null, "For every integer you are off from the second auto-generated guess, you will gain 0.5%  or lose 0.25% distance from your previously calculated shot.");
        JOptionPane.showMessageDialog(null, "However for chipping and putting, you will be guessing one time which will determine if it goes long or short.");
        JOptionPane.showMessageDialog(null, "Additionally, you will be able to choose how much power you want to use, ONLY for chipping and putting.");
        JOptionPane.showMessageDialog(null, "While chipping you will be using your 60 degree wedge. You must chip from 50 yards and closer.");
        JOptionPane.showMessageDialog(null, "When you are 20 yards in, you will also have to putt.");
        JOptionPane.showMessageDialog(null, "If you are inside 3 yards, the hole will finish automatically.");
        JOptionPane.showMessageDialog(null, "It is recommended to write down the following club yardages if you want to get a good score.");
        JOptionPane.showMessageDialog(null, "Driver (1): 275 yards");
        JOptionPane.showMessageDialog(null, "3 wood (3): 250 yards");
        JOptionPane.showMessageDialog(null, "4 hybrid (4): 225 yards");
        JOptionPane.showMessageDialog(null, "5 iron (5): 210 yards");
        JOptionPane.showMessageDialog(null, "6 iron (6): 195 yards");
        JOptionPane.showMessageDialog(null, "7 iron (7): 180 yards");
        JOptionPane.showMessageDialog(null, "8 iron (8): 165 yards");
        JOptionPane.showMessageDialog(null, "9 iron (9): 150 yards");
        JOptionPane.showMessageDialog(null, "Pitching Wedge (10): 125 yards");
        JOptionPane.showMessageDialog(null, "52 Degree Wedge (52): 100 yards");
        JOptionPane.showMessageDialog(null, "56 Degree Wedge (56): 85 yards");
        JOptionPane.showMessageDialog(null, "60 Degree Wedge (60): 70 yards");
        JOptionPane.showMessageDialog(null, "Putter: 20 yards");
    }

    public double shotDistance(int club, int guess1, int guess2, int randomNum1, int randomNum2) {
        double distance = 0;
        double baseDistance = 0;
        double distanceModifier1 = 0.0025;
        double distanceModifier2 = 0.005;

        switch (club) {
            case 1:
                baseDistance = 275;
                break;
            case 3:
                baseDistance = 250;
                break;
            case 4:
                baseDistance = 225;
                break;
            case 5:
                baseDistance = 210;
                break;
            case 6:
                baseDistance = 195;
                break;
            case 7:
                baseDistance = 180;
                break;
            case 8:
                baseDistance = 165;
                break;
            case 9:
                baseDistance = 150;
                break;
            case 10:
                baseDistance = 125;
                break;
            case 52:
                baseDistance = 100;
                break;
            case 56:
                baseDistance = 85;
                break;
            case 60:
                baseDistance = 70;
                break;
            default:
                break;
        }

        double guessDiff1 = Math.abs(guess1 - randomNum1);
        if (guessDiff1 != 0) {
            distanceModifier1 *= guessDiff1;
            distanceModifier1 *= (guess1 < randomNum1 ? -1 : 1);
        }

        distance = baseDistance * (1 + distanceModifier1);

        double guessDiff2 = Math.abs(guess2 - randomNum2);
        if (guessDiff2 != 0) {
            distanceModifier2 *= guessDiff2;
            distanceModifier2 *= (guess2 < randomNum2 ? -1 : 1);
        }

        distance *= (1 + distanceModifier2);

        return distance;
    }

    public boolean hazardChance() {
        boolean inHazard = false;
        int hazardRandom = (int)((Math.random() * 100) + 1);
        if(hazardRandom == 1 || hazardRandom == 2 || hazardRandom == 3) {
            inHazard = true;
        }
        return inHazard;
    }

    public double chipping() {
        double chipDistance = 0;
        String temp = "";
        double chipPower = 0;
        int chipGuess = 0;
        int randomNum3 = (int)((Math.random() * 100) + 1);
        do {
            temp = JOptionPane.showInputDialog("Choose the chip power (as a decimal).");
            chipPower = Double.parseDouble(temp);
        } while(chipPower <= 0);
        do {
            temp = JOptionPane.showInputDialog("Choose a number 1-100. (guess/power)");
            chipGuess = Integer.parseInt(temp);
        } while(chipGuess < 1 || chipGuess > 100);
        if((chipGuess - randomNum3) < 0) {
            chipDistance = chipPower * 70 * (1 - (0.01 * Math.abs(chipGuess - randomNum3)));
        }
        else if ((chipGuess - randomNum3) > 0) {
            chipDistance = chipPower * 70 * (1 + (0.01 * Math.abs(chipGuess - randomNum3)));
        }
        else {
            chipDistance = chipPower * 70;
        }
        return chipDistance;
    }
   
    public double putting() {
        double puttDistance = 0;
        double puttPower = 0;
        String temp = "";
        int puttGuess = 0;
        int randomNum4 = (int)((Math.random() * 100) + 1);
        do {
            temp = JOptionPane.showInputDialog("Choose the putt power (as a decimal).");
            puttPower = Double.parseDouble(temp);
        } while(puttPower <= 0);
        do {
            temp = JOptionPane.showInputDialog("Choose a number 1-100. (guess/power)");
            puttGuess = Integer.parseInt(temp);
        } while(puttGuess < 1 || puttGuess > 100);
        if((puttGuess - randomNum4) < 0) {
            puttDistance = puttPower * 20 * (1 - (0.01 * Math.abs(puttGuess - randomNum4)));
        }
        else if ((puttGuess - randomNum4) > 0) {
            puttDistance = puttPower * 20 * (1 + (0.01 * Math.abs(puttGuess - randomNum4)));
        }
        else {
            puttDistance = puttPower * 20;
        }
        return puttDistance;
    }
}
