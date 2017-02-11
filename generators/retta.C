
void retta() {

  ofstream out;
  out.open("dat.txt");

  for (int i = 0; i < 50; i++) {

    float x = 2.0 + 1.0 * i + gRandom->Gaus(0.0, 0.5);

    float y = 12.7 + 1.1 * x + gRandom->Gaus(0.0, 0.7);

    float ey = 0.7;

    cout << "x = " << x << " y = " << y << " ey = " << ey << endl;

    out << x << " " << y << " " << ey << endl;
  }

  out.close();

}
