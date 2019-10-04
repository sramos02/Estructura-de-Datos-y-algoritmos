//---- VERIFICACIÓN----

//1 Numeros perfectos
//P: num >= 0
bool perfecto(int num){
  bool p = false;
  int aux = 0;

  for(int i = 0; i < num; i++){
    if(n % i == 0) aux+= i;
    if(num == aux) p = true;
  } 
  
  return p;
}
//Q: p = (n = (SUM(0 <= u < num : n mod u = 0 : u)))

//2 Numeros triangulares
//P: num >= 0
bool triangular(int num){
  bool b;
  int aux = 0;
  
  for(int i = 0; i < num; i++){
    aux+= i;
    if(num == aux) p = true;
  } 
  
  return b;
}
//Q: p = (Ek : int : (n = SUM(0 <= u < k : u)))

//3 Vector melchoriforme
//P: v.lenght > 0
bool melchoriforme(int V[]){
  int aux = 0;
  
  //Calcula la suma de todos los elementos del vector
  for(int i = 0; i < V.length(); i++){aux += V[j];}
  
  //Calcula para cada numero si existe alguno rubio
 for(int i = 0; i < V.length(); i++){
  if(V[i] == (aux - V[i])) return true;
 }
 
  return false;
}
//Q: Eu : 0 <= u < v.length : V[u] = SUM(w : 0 <= w < v..length && u != w : V[w])

//4 Vector gaspariforme
//P: v.length() >= 0
bool gaspariforme(int V[]){
  int total = 0;
  
  //Suma total es cero
  for(int i = 0; i < V.length(); i++) total += V[i];
  if(total != 0) return false;

  //Sumas parciales no negativas
  for(int i = 0; i < V.length(); i++){
    int aux = 0;
    for(int j = 0; j <= i; j++) aux += V[j];
    if(aux < 0) return false;
  }
  
  return true;
}
//suma(A, x) = SUM(w : 0 <= w < x : V[w])
//Q: b = PTi : 0 <= i <= N : suma(V, u) = 0 && suma(V, V.length) = 0

//5 Vector capicua
//P: v.length() > 0
bool capicua(int V[]){ 
    
}
//Q: 
