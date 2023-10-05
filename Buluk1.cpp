#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool compararSinMayusculas(const string& str1, const string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    for (size_t i = 0; i < str1.size(); ++i) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Presiona 'A2' para activar el modo autónomo..." << endl;
    string inicio;
    cin >> inicio;

    if (!compararSinMayusculas(inicio, "A2")) {
        cout << "Modo autónomo no activado. Saliendo del programa." << endl;
        return 0;
    }

    double distanciaCoche = 50.0;
    double gradosCoche = 260.0;
    double alturaGarra = 0.0;
    double distanciaDerechaGarra = 0.0;
    vector<double> avanceRobot;
    vector<double> gradosRobot;

    double distanciaCocheEntrega = 35.0;
    double gradosCocheEntrega = 310.0;

    cout << "Durante el modo autónomo, el robot se movió 10 metros y giró 50 grados, ahora debes avanzar 50m y girar 260 grados" << endl;
    cout << "Ahora estás en modo 'Driver', buena suerte" << endl;
    cout << "Control del robot:" << endl;
    cout << " - Para moverte, ingresa 'A0' (Palanca Izquierda)" << endl;
    cout << " - Para girar, ingresa 'POV' (Cruceta)" << endl;
    cout << " - Para verificar el coche, ingresa '3' (Botón Y)" << endl;
    cout << " - Para verificar la garra, ingresa '1' (Botón B)" << endl;
    cout << " - Para entrar a 'Pits', ingresa '2' (Botón XBOX)" << endl;
    cout << " - Para salir, ingresa 'SEIS' (Select)" << endl;

    while (true) {
        string accion;
        cout << "Ingresa la acción: ";
        cin >> accion;

        if (compararSinMayusculas(accion, "A0")) {
            cout << "Ingresa distancia para moverte: ";
            double distanciaMover;
            cin >> distanciaMover;
            avanceRobot.push_back(distanciaMover);
            double distanciaRelativa = distanciaCoche;
            for (const auto& distancia : avanceRobot) {
                distanciaRelativa -= distancia;
                cout << "Avanzando hacia adelante" << endl;
            }
            cout << "Falta: " << distanciaRelativa << " m, " << gradosCoche << " grados." << endl;
        } else if (compararSinMayusculas(accion, "POV")) {
            cout << "Ingresa grados para girar: ";
            double gradosGirar;
            cin >> gradosGirar;
            gradosRobot.push_back(gradosGirar);
            for (const auto& grados : gradosRobot) {
                gradosCoche -= grados;
            }
            cout << "Girando " << gradosGirar << " grados." << endl;
        } else if (compararSinMayusculas(accion, "3")) {
            cout << "Altura Coche: -20 cm, Derecha Coche: 30 cm." << endl;
            double distanciaRelativa = distanciaCoche;
            for (const auto& distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            cout << "Falta: " << distanciaRelativa << " m, " << gradosCoche << " grados." << endl;
            if (distanciaRelativa == 0.0 && gradosCoche == 0.0) {
                cout << "Puedes entrar al modo 'a los pits'." << endl;
            }
        } else if (compararSinMayusculas(accion, "1")) {
            cout << "Altura Garra: " << alturaGarra << " cm, Derecha Garra: " << distanciaDerechaGarra << " cm." << endl;
        } else if (compararSinMayusculas(accion, "2")) {
            double distanciaRelativa = distanciaCoche;
            for (const auto& distancia : avanceRobot) {
                distanciaRelativa -= distancia;
            }
            if (distanciaRelativa == 0.0 && gradosCoche == 0.0) {
                cout << "Entrando al modo 'A los Pits'" << endl;
                while (true) {
                    cout << " - Para usar el pistón que mueve la pinza a la derecha, ingresa 'A3' (Gatillo Derecho)" << endl;
                    cout << " - Para usar el pistón que mueve la pinza a la izquierda, ingresa 'A2' (Gatillo Izquierdo)" << endl;
                    cout << " - Para usar el pistón que mueve la pinza hacia abajo, ingresa 'A4' (Palanca Derecha)" << endl;
                    cout << " - Para intentar recoger el coche, ingresa '2' (Botón X)" << endl;
                    cout << " - Para salir de 'Pits', ingresa 'SIETE'" << endl;

                    string accionPits;
                    cout << "Ingresa la acción: ";
                    cout << "El coche se encuentra 30cm a la derecha y -20cm hacia abajo";
                    cin >> accionPits;

                    if (compararSinMayusculas(accionPits, "A3") || compararSinMayusculas(accionPits, "a3")) {
                        distanciaDerechaGarra += 5.0;
                        cout << "Moviendo garra 5 cm a la derecha." << endl;
                    } else if (compararSinMayusculas(accionPits, "A2") || compararSinMayusculas(accionPits, "a2")) {
                        distanciaDerechaGarra -= 5.0;
                        cout << "Moviendo garra 5 cm a la izquierda." << endl;
                    } else if (compararSinMayusculas(accionPits, "A4") || compararSinMayusculas(accionPits, "a4")) {
                        alturaGarra -= 5.0;
                        cout << "Moviendo garra 5 cm hacia abajo." << endl;
                    } else if (compararSinMayusculas(accionPits, "2")) {
                        if (alturaGarra == -20.0 && distanciaDerechaGarra == 30.0) {
                            cout << "Recogiendo coche y cambiando las llantas... ¡Éxito!" << endl;
                            break;
                        } else {
                            cout << "Coordenadas de garra incorrectas para recoger el coche." << endl;
                        }
                    } else if (compararSinMayusculas(accionPits, "SIETE")) {
                        cout << "Saliendo del modo 'A los Pits'." << endl;
                        break;
                    } else {
                        cout << "Acción no reconocida" << endl;
                    }
                }
            } else {
                cout << "No puedes entrar al modo 'A los Pits' hasta que llegues al coche." << endl;
            }
        } else if (compararSinMayusculas(accion, "SIETE")) {
            break;
        } else {
            cout << "Acción no reconocida" << endl;
        }
    }

    // Modo "Entrega" después de agarrar el coche
    while (true) {
        cout << "Has agarrado el coche. Debes ir a entregarlo." << endl;
        cout << "Distancia para entrega: " << distanciaCocheEntrega << " m, Girar: " << gradosCocheEntrega << " grados." << endl;

        string accionEntrega;
        double distanciaMetros = 0.0;
        double gradosGirar = 0.0;

        while (true) {
            cout << "Ingresa la acción ('A0' para moverte, 'POV' para girar, 'CINCO' para salir): ";
            cin >> accionEntrega;

            if (compararSinMayusculas(accionEntrega, "A0")) {
                cout << "Ingresa distancia para moverte: ";
                cin >> distanciaMetros;
            } else if (compararSinMayusculas(accionEntrega, "POV")) {
                cout << "Ingresa grados para girar: ";
                cin >> gradosGirar;
            } else if (compararSinMayusculas(accionEntrega, "CINCO")) {
                cout << "Saliendo del modo 'Entrega'." << endl;
                break;
            } else {
                cout << "Acción no reconocida" << endl;
                continue;
            }

            distanciaCocheEntrega -= distanciaMetros;
            gradosCocheEntrega -= gradosGirar;

            cout << "Falta: " << distanciaCocheEntrega << " m, Girar: " << gradosCocheEntrega << " grados." << endl;

            if (distanciaCocheEntrega <= 0.0 && gradosCocheEntrega <= 0.0) {
                cout << "Llegaste al punto de entrega, ¿soltar coche? ('CERO' para sí, 'N' para no, 'A3' para activar la red para recoger las piezas dentro del área de entrega";
                string respuesta;
                cin >> respuesta;
                if (compararSinMayusculas(respuesta, "CERO")) {
                    cout << "¡Coche entregado con éxito!" << endl;
                    break;
                } else if (compararSinMayusculas(respuesta, "N")) {
                    break;
                } else if (compararSinMayusculas(respuesta, "A3")) {
                    cout << "Red activada, piezas del área de entrega recogidas" << endl;
                    cout << "Coche entregado, ¡felicidades!" << endl;
                }
            }
        }
        break; // Salir del bucle del modo "Entrega"
    }

    return 0;
}