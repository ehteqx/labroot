
void seno() {

  ofstream out;
  out.open("dat.txt");

  for (int i = 0; i < 500; i++) {

    float x = -5 + 0.01 * i + gRandom->Gaus(0.0, 0.1);

    float y = 5.35 + 3.2 * sin(x * 2.12 + 0.12) + gRandom->Gaus(0.0, 0.3);

    float ey = 0.3;

    cout << "x = " << x << " y = " << y << " ey = " << ey << endl;

    out << x << " " << y << " " << ey << endl;
  }

  out.close();
}
