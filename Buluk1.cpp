#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    double distanciaCoche = 50.0;
    double gradosCoche = 260.0;
    double alturaGarra = 0.0;
    double distanciaDerechaGarra = 0.0;
    vector<double> avanceRobot;
    vector<double> gradosRobot;
    int cocheagarrado = 0;

    double distanciaCocheEntrega = 35.0;
    double gradosCocheEntrega = 310.0;

    cout << "Durante los 15 segundos de autónomo, el robot avanzó 25 metros y giró 130 grados" << endl;
    
    cout << "Control del robot:" << endl;
    cout << " - Para moverte, ingresa 'A0' (Palanca Izquierda)" << endl;
    cout << " - Para girar, ingresa 'POV' (Cruceta)" << endl;
    cout << " - Para verificar el coche, ingresa '3' (Botón Y)" << endl;
    cout << " - Para verificar la garra, ingresa '1' (Botón B)" << endl;
    cout << " - Para entrar a 'Pits', ingresa '2' (Botón XBOX)" << endl;
    cout << " - Para salir, ingresa '7' (Select)" << endl;

    while (true) {
        string accion;
        cout << "Ingresa la acción: ";
        cin >> accion;

        if (accion == "A0") {
            cout << "Ingresa distancia para moverte: ";
            double distanciaMover;
            cin >> distanciaMover;
            avanceRobot.push_back(distanciaMover);
            double distanciaRelativa = distanciaCoche;
            for (const auto &distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            cout << "Falta: " << distanciaRelativa << " m, " << gradosCoche << " grados." << endl;
        } else if (accion == "POV") {
            cout << "Ingresa grados para girar: ";
            double gradosGirar;
            cin >> gradosGirar;
            gradosRobot.push_back(gradosGirar);
            for (const auto &grados : gradosRobot) {
                gradosCoche -= grados;
            }
            cout << "Girando " << gradosGirar << " grados." << endl;
        } else if (accion == "3") {
            cout << "Altura Coche: -20 cm, Derecha Coche: 30 cm." << endl;
            double distanciaRelativa = distanciaCoche;
            for (const auto &distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            cout << "Falta: " << distanciaRelativa << " m, " << gradosCoche << " grados." << endl;
            if (distanciaRelativa == 0.0 && gradosCoche == 0.0) {
                cout << "Puedes entrar al modo 'a los pits'." << endl;
            }
        } else if (accion == "1") {
            cout << "Altura Garra: " << alturaGarra << " cm, Derecha Garra: " << distanciaDerechaGarra << " cm." << endl;
        } else if (accion == "2") {
            double distanciaRelativa = distanciaCoche;
            for (const auto &distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            if (distanciaRelativa == 0.0 && gradosCoche == 0.0) {
                cout << "Entrando al modo 'A los Pits'" << endl;
                while (true) {
                    cout << " - Para mover la pinza a la derecha, ingresa 'A3' (Gatillo Derecho)" << endl;
                    cout << " - Para mover la pinza a la izquierda, ingresa 'A2' (Gatillo Izquierdo)" << endl;
                    cout << " - Para mover la pinza hacia abajo, ingresa 'A4' (Palanca Derecha)" << endl;
                    cout << " - Para intentar recoger el coche, ingresa '2' (Botón X)" << endl;
                    cout << " - Para salir de 'Pits', ingresa '7'" << endl;

                    string accionPits;
                    cout << "Ingresa la acción: ";
                    cout << "El coche se encuentra 30cm a la derecha y -20cm hacia abajo";
                    cin >> accionPits;

                    if (accionPits == "A3") {
                        distanciaDerechaGarra += 5.0;
                        cout << "Moviendo garra 5 cm a la derecha." << endl;
                    } else if (accionPits == "A2") {
                        distanciaDerechaGarra -= 5.0;
                        cout << "Moviendo garra 5 cm a la izquierda." << endl;
                    } else if (accionPits == "A4") {
                        alturaGarra -= 5.0;
                        cout << "Moviendo garra 5 cm hacia abajo." << endl;
                    } else if (accionPits == "2") {
                        if (alturaGarra == -20.0 && distanciaDerechaGarra == 30.0) {
                            cout << "Recogiendo coche y cambiando las llantas... ¡Éxito!" << endl;
                            cocheagarrado = 1; // Coche ha sido agarrado
                            break;
                        } else {
                            cout << "Coordenadas de garra incorrectas para recoger el coche." << endl;
                        }
                    } else if (accionPits == "7") {
                        cout << "Saliendo del modo 'A los Pits'." << endl;
                        break;
                    } else {
                        cout << "Acción no reconocida" << endl;
                    }
                }
            } else {
                cout << "No puedes entrar al modo 'A los Pits' hasta que llegues al coche." << endl;
            }
        } else if (accion == "7") {
            break;
        } else {
            cout << "Acción no reconocida" << endl;
        }
    }

    // Modo "Entrega" después de agarrar el coche
    while (cocheagarrado) {
        cout << "Has agarrado el coche. Debes ir a entregarlo." << endl;
        cout << "Distancia para entrega: " << distanciaCocheEntrega << " m, Girar: " << gradosCocheEntrega << " grados." << endl;
        
        string accionEntrega;
        double distanciaMetros = 0.0;
        double gradosGirar = 0.0;
        
        while (true) {
            cout << "Ingresa la acción ('A0' para moverte, 'POV' para girar, '5' para salir): ";
            cin >> accionEntrega;

            if (accionEntrega == "A0") {
                cout << "Ingresa distancia para moverte: ";
                cin >> distanciaMetros;
            } else if (accionEntrega == "POV") {
                cout << "Ingresa grados para girar: ";
                cin >> gradosGirar;
            } else if (accionEntrega == "5") {
                cout << "Saliendo del modo 'Entrega'." << endl;
                cocheagarrado = 0; // Salir del modo "Entrega"
                break;
            } else {
                cout << "Acción no reconocida" << endl;
                continue;
            }

            distanciaCocheEntrega -= distanciaMetros;
            gradosCocheEntrega -= gradosGirar;

            cout << "Falta: " << distanciaCocheEntrega << " m, Girar: " << gradosCocheEntrega << " grados." << endl;

            if (distanciaCocheEntrega <= 0.0 && gradosCocheEntrega <= 0.0) {
                cout << "Llegaste al punto de entrega, ¿soltar coche? (0(Sí)/N(no)): ";
                string respuesta;
                cin >> respuesta;
                if (respuesta == "0") {
                    cout << "¡Coche entregado con éxito!" << endl;
                    cocheagarrado = 0; // Marcar que el coche ha sido entregado
                    break;
                }
                else if (respuesta == "N" || respuesta == "n") {
                    break;
                }
            }
        }
    }

    return 0;
}