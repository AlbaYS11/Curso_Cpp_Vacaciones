//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.


import javax.swing.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static int existe(String aux, ArrayList<String> e){
            for (int i = 0; i < e.size(); i++){
                if (aux.equalsIgnoreCase(e.get(i)))
                    return i;
        }
            return -1;
    }

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);

        ArrayList<Integer> puntajes = new ArrayList<>();
        ArrayList<String> nombres = new ArrayList<>();

        int opc, ind;
        String aux;

try {

    do {

        System.out.println("\n--- MENU ---");
        System.out.println("1. Agregar jugador.\n2. Mostrar jugadores.\n3. Buscar Jugador.\n" +
                "4. Calcular promedio de jugadores.\n5. Eliminar jugador.\n0. Salir.\n");
        opc = leer.nextInt();

        switch (opc) {

            case 1:

                System.out.println("Inserta el nombre del jugador:");
                nombres.add(leer.next());

                System.out.println("Inserta el puntaje del jugador:");
                puntajes.add(leer.nextInt());
                break;

            case 2:

                System.out.println("Jugadores en el marcador:");
                for (int i = 0; i < nombres.size(); i++) {

                    System.out.println((i + 1) + ". " + nombres.get(i) + ": " + puntajes.get(i));
                }
                break;

            case 3:

                System.out.println("Buscar un jugador en el marcador:");
                aux = leer.next();

                ind = existe(aux, nombres);
                if (ind != -1){
                    System.out.println((ind + ". " + nombres.get(ind) + ": " + puntajes.get(ind)));
                }else{
                    System.out.println("Error. Ese jugador no existe.");
                }

                break;

            case 4:

                if (puntajes.isEmpty()) {
                    System.out.println("No hay jugadores registrados.");
                } else {
                    double sum = 0;
                    for (int p : puntajes) {
                        sum += p;
                    }
                    System.out.println(sum / puntajes.size());
                }

                break;
            case 5:

                System.out.println("Ingresa el jugador que quieres eliminar:");
                aux = leer.next();

                ind = existe(aux, nombres);
                if (ind != -1){

                    puntajes.remove(ind);
                    nombres.remove(ind);
                    System.out.println("Jugador eliminado.");
                }else{

                    System.out.println("Error. Ese jugador no existe.");
                }
                break;

            default:

                System.out.println("Has salido.");
                break;
        }
    } while (opc > 0 && opc < 6);

}catch(Exception e){

    System.out.println("Error");

}
    }
}