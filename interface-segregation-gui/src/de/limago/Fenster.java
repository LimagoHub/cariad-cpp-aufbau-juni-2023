package de.limago;

import java.awt.*;
import java.awt.event.WindowAdapter;


public class Fenster extends Frame {


    public Fenster()  {

        setSize(300, 300);

        Button button = new Button("Drück mich");

        new WindowAdapter(){};
        add(button);




    }


    public static void main(String[] args) {

        new Fenster().setVisible(true);
    }



}
