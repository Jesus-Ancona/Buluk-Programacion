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

    cout << "Control del robot:" << endl;
    cout << " - Para moverte, ingresa 'PI' (Palanca Izquierda)" << endl;
    cout << " - Para girar, ingresa 'C' (Cruceta)" << endl;
    cout << " - Para verificar el coche, ingresa 'Y' (Botón Y)" << endl;
    cout << " - Para verificar la garra, ingresa 'B' (Botón B)" << endl;
    cout << " - Para entrar a 'Pits', ingresa 'XBOX' (Botón XBOX)" << endl;
    cout << " - Para salir, ingresa 'S' (Select)" << endl;

    while (true) {
        string accion;
        cout << "Ingresa la acción: ";
        cin >> accion;

        if (accion == "PI") {
            cout << "Ingresa distancia para moverte: ";
            double distanciaMover;
            cin >> distanciaMover;
            avanceRobot.push_back(distanciaMover);
            double distanciaRelativa = distanciaCoche;
            for (const auto &distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            cout << "Falta: " << distanciaRelativa << " m, " << gradosCoche << " grados." << endl;
        } else if (accion == "C") {
            cout << "Ingresa grados para girar: ";
            double gradosGirar;
            cin >> gradosGirar;
            gradosRobot.push_back(gradosGirar);
            for (const auto &grados : gradosRobot) {
                gradosCoche -= grados;
            }
            cout << "Girando " << gradosGirar << " grados." << endl;
        } else if (accion == "Y") {
            cout << "Altura Coche: -20 cm, Derecha Coche: 30 cm." << endl;
            double distanciaRelativa = distanciaCoche;
            for (const auto &distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            cout << "Falta: " << distanciaRelativa << " m, " << gradosCoche << " grados." << endl;
            if (distanciaRelativa == 0.0 && gradosCoche == 0.0) {
                cout << "Puedes entrar al modo 'a los pits'." << endl;
            }
        } else if (accion == "B") {
            cout << "Altura Garra: " << alturaGarra << " cm, Derecha Garra: " << distanciaDerechaGarra << " cm." << endl;
        } else if (accion == "XBOX") {
            double distanciaRelativa = distanciaCoche;
            for (const auto &distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            if (distanciaRelativa == 0.0 && gradosCoche == 0.0) {
                cout << "Entrando al modo 'A los Pits'" << endl;
                while (true) {
                    cout << " - Para mover la pinza a la derecha, ingresa 'GD' (Gatillo Derecho)" << endl;
                    cout << " - Para mover la pinza a la izquierda, ingresa 'GI' (Gatillo Izquierdo)" << endl;
                    cout << " - Para mover la pinza hacia abajo, ingresa 'PD' (Palanca Derecha)" << endl;
                    cout << " - Para intentar recoger el coche, ingresa 'X' (Botón X)" << endl;
                    cout << " - Para salir de 'Pits', ingresa 'S'" << endl;

                    string accionPits;
                    cout << "Ingresa la acción: ";
                    cout << "El coche se encuentra 30cm a la derecha y -20cm hacia abajo";
                    cin >> accionPits;

                    if (accionPits == "GD") {
                        distanciaDerechaGarra += 5.0;
                        cout << "Moviendo garra 5 cm a la derecha." << endl;
                    } else if (accionPits == "GI") {
                        distanciaDerechaGarra -= 5.0;
                        cout << "Moviendo garra 5 cm a la izquierda." << endl;
                    } else if (accionPits == "PD") {
                        alturaGarra -= 5.0;
                        cout << "Moviendo garra 5 cm hacia abajo." << endl;
                    } else if (accionPits == "X") {
                        if (alturaGarra == -20.0 && distanciaDerechaGarra == 30.0) {
                            cout << "Recogiendo coche y cambiando las llantas... ¡Éxito!" << endl;
                            break;
                        } else {
                            cout << "Coordenadas de garra incorrectas para recoger el coche." << endl;
                        }
                    } else if (accionPits == "S") {
                        cout << "Saliendo del modo 'A los Pits'." << endl;
                        break;
                    } else {
                        cout << "Acción no reconocida" << endl;
                    }
                }
            } else {
                cout << "No puedes entrar al modo 'A los Pits' hasta que llegues al coche." << endl;
            }
        } else if (accion == "S") {
            break;
        } else {
            cout << "Acción no reconocida" << endl;
        }
    }

    return 0;
}