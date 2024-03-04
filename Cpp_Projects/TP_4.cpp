#include <iostream>
using namespace std;

int main(){
    float A, B, C;
    cout << "donnez la moyennes de Mohamed: ";
    cin >> A;
    cout << "donnez la moyennes de Amine: ";
    cin >> B;
    cout << "donnez la moyennes de Moustafa: ";
    cin >> C;
    cout << "Tous les etudiant on reussit dans leurs examen: " << (A > 10 && B > 10 && C > 10) << endl;
    cout << "Au moins un etudiant a reussit dans l'examen: " << (A > 10 || B > 10 || C > 10) << endl;
    cout << "Seul amine a reussit dans l'examen: " << (B > 10 && A <= 10 && C <= 10) << endl;
    cout << "Un seul etudiant a reussi dans l'examen: " << ((A > 10 && B <= 10 &&  C <= 10) || (B > 10 && A <= 10 && C <= 10) || (C > 10 && B <= 10 && C <= 10)) << endl;
    cout << "Deux etudiants ont reussi dans l'examen: " << ((A > 10 && B > 10 && C <= 10) || (A > 10 && C > 10 && B <= 10) || (B > 10 && C > 10 && A <= 10)) << endl;
    cout << "Amine et Mohamed on reussit dans leurs examen et ont obtenu la meme moyenne: " << (A > 10 && B > 10 && A == B) << endl;
    cout << "Seulement Amine et Mohamed on reussit dans leur examen et ont obtenu la meme moyenne: " << (A > 10 && B > 10 && A == B && C <= 10) << endl; 
    cout << "Mohamed a obtenu la plus grande moyenne: " << (A > B && A > C) << endl;
    cout << "Un des etudiant a obtenu une moyenne de 15/20: " << (A == 15 || B == 15 || C == 15) << endl;
    cout << "Les trois etudiants on obtenu la meme moyenne: " << (A == B && B == C) << endl;
    cout << "Les etudiants ont obtenu des moyennes differentes: " << (A != B && B != C && A != C) << endl;
    system("pause");
    return 0;
}