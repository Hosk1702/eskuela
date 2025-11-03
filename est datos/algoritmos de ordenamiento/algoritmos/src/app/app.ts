import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { CommonModule } from '@angular/common'; 
import { BaseChartDirective } from 'ng2-charts';

// --- CAMBIO 1: Importar Chart y registerables ---
import { ChartConfiguration, Chart, registerables } from 'chart.js'; 

@Component({
  selector: 'app-root',
  standalone: true, 
  imports: [
    RouterOutlet,
    CommonModule,   
    BaseChartDirective
  ],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {

  // 1. ESTADO DE LA UI
  nivelOrden: string = 'Aleatorio';
  cantidadElementos: number = 5000;
  ranking: string = 'N/A';
  configuracionActual: string = '';
  ejecutando: boolean = false;

  // 2. DATOS DE LA GRÁFICA (Chart.js)
  public barChartData: ChartConfiguration<'bar'>['data'] = {
    labels: [
      'Bubble Sort', 
      'Insertion Sort', 
      'Selection Sort', 
      'Quick Sort', 
      'Merge Sort',
      'Heap Sort',
      'Shell Sort',
      'Bucket Sort'
    ],
    datasets: [
      { data: [], label: 'Tiempo (ms)', backgroundColor: 'rgba(90, 100, 255, 0.7)' }
    ]
  };
  public barChartOptions: ChartConfiguration<'bar'>['options'] = {
    responsive: true,
    animation: {
      duration: 400 
    },
    scales: {
      y: {
        beginAtZero: true,
        ticks: {
          callback: (value) => `${value} ms` 
        }
      }
    }
  };


  constructor() {
    Chart.register(...registerables);
  }

async onExecuteAlgorithms() {
    if (this.ejecutando) return; 
    
    this.ejecutando = true;
    this.configuracionActual = `${this.nivelOrden} - ${this.cantidadElementos} elementos`;
    this.ranking = 'Calculando...';

    
    const algorithms = [
      { name: 'Bubble Sort', fn: this.bubbleSort.bind(this) },
      { name: 'Insertion Sort', fn: this.insertionSort.bind(this) },
      { name: 'Selection Sort', fn: this.selectionSort.bind(this) },
      { name: 'Quick Sort', fn: this.quickSort.bind(this) },
      { name: 'Merge Sort', fn: this.mergeSort.bind(this) },
      { name: 'Heap Sort', fn: this.heapSort.bind(this) },
      { name: 'Shell Sort', fn: this.shellSort.bind(this) },
      { name: 'Bucket Sort', fn: this.bucketSort.bind(this) },
    ];

    const times = Array(algorithms.length).fill(0);
    const newResults: { name: string, time: number }[] = []; 

    const baseArray = this.generateArray(this.nivelOrden, this.cantidadElementos);
    
    let i = 0;
    for (const algo of algorithms) {
      const arrCopy = [...baseArray]; 
      
      const t0 = performance.now();
      try {
        algo.fn(arrCopy); 
      } catch (e) {
        console.error(`Error en ${algo.name}:`, e);
      }
      const t1 = performance.now();
      
      const timeMs = t1 - t0;
      newResults.push({ name: algo.name, time: timeMs });
      
      times[i] = timeMs;

      this.barChartData = {
        labels: this.barChartData.labels, 
        datasets: [
          {
            ...this.barChartData.datasets[0],
            data: [...times] 
          }
        ]
      };

      await new Promise(resolve => setTimeout(resolve, 50));
      i++;
    }

    const fastest = newResults.sort((a, b) => a.time - b.time)[0];
    this.ranking = fastest.name;
    this.ejecutando = false;
  }

  
  seleccionarNivel(nivel: string) {
    this.nivelOrden = nivel;
  }

  seleccionarCantidad(cantidad: number) {
    this.cantidadElementos = cantidad;
  }

  
  private generateArray(tipo: string, cantidad: number): number[] {
    const arr: number[] = [];
    for (let i = 1; i <= cantidad; i++) {
      arr.push(i);
    }

    switch (tipo) {
      case 'Ordenado':
        return arr;
      
      case 'Inverso':
        return arr.reverse();
      
      case 'Aleatorio':
        for (let i = arr.length - 1; i > 0; i--) {
          const j = Math.floor(Math.random() * (i + 1));
          [arr[i], arr[j]] = [arr[j], arr[i]];
        }
        return arr;
        
      case 'Casi Ordenado':
        const swaps = Math.floor(cantidad * 0.1);
        for(let i = 0; i < swaps; i++) {
          const rand1 = Math.floor(Math.random() * cantidad);
          const rand2 = Math.floor(Math.random() * cantidad);
          [arr[rand1], arr[rand2]] = [arr[rand2], arr[rand1]];
        }
        return arr;
        
      default:
        return arr; 
    }
  }


  private bubbleSort(arr: number[]): number[] {
    let tam = arr.length;
    let swapped = true;
    while (swapped == true) {
        swapped = false;
        for (let i=0; i < tam-1; i++) {
            if (arr[i]> arr[i+1]){
                let temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
    }
    return arr;
  }

 
  private insertionSort(arr: number[]): number[] {
    for(let i = 1 ; i < arr.length ; i++){
        let temp = arr[i];
        let j = i-1;
        while(j>=0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp
    }
    return arr;
  }


  private selectionSort(arr: number[]): number[] {
    for(let i = 0 ; i < arr.length ; i++){
        let peque = i;
        for(let j=i+1 ; j < arr.length ; j++ ){
            if (arr[peque] > arr[j]){
                peque = j;
            } 
        }
        let temp = arr[peque];
        arr[peque] = arr [i];
        arr[i] = temp;
    }
    return arr;
  }


  private quickSort(arr: number[]): number[] {
    this.quicsort_internal(arr, 0, arr.length - 1);
    return arr;
  }
  private cambiar(arr: number[], j: number, k: number){
    let temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;
  }
  private particion(arr: number[], l: number, h: number){
    let pivote = arr[h];
    let j = l-1;
    for(let k = l; k < h; k++){
        if (arr[k] <= pivote){
            j += 1;
            this.cambiar(arr,j,k);
        }
    }
    this.cambiar(arr, j+1, h);
    return j+1;
  }
  private quicsort_internal(arr: number[], l: number, h: number){
    if (l<h){
        let pivoteindx = this.particion(arr,l,h);
        this.quicsort_internal(arr,l,pivoteindx-1);
        this.quicsort_internal(arr,pivoteindx+1,h);    
    }
  }

 
  private mergeSort(arr: number[]): number[] {
    this.mergesort_internal(arr, 0, arr.length - 1);
    return arr;
  }
  private merge(a: number[], l: number, m: number, r: number) {
    let a1 = m - l + 1; 
    let a2 = r - m;     
    let L = new Array(a1);
    let R = new Array(a2);
    for (let i = 0; i < a1; i++) L[i] = a[l + i];
    for (let j = 0; j < a2; j++) R[j] = a[m + 1 + j];
    let i = 0, j = 0, k = l; 
    while (i < a1 && j < a2) {
        if (L[i] <= R[j]) { 
            a[k] = L[i]; i++;
        } else {            
            a[k] = R[j]; j++;      
        }
        k++; 
    }
    while (i < a1) { a[k] = L[i]; i++; k++; }
    while (j < a2) { a[k] = R[j]; j++; k++; }
  }
  private mergesort_internal(a: number[], l: number, r: number) {
    if (l < r) {
        let m = Math.floor(l + (r - l) / 2);
        this.mergesort_internal(a, l, m);
        this.mergesort_internal(a, m + 1, r);
        this.merge(a, l, m, r); 
    }
  }


  private heapSort(arr: number[]): number[] {
    this.heapsort_internal(arr);
    return arr;
  }
  private heapify(arr: number[], n: number, i: number) {
    let masGrande = i;
    let izquierda = 2 * i + 1; 
    let derecha = 2 * i + 2;   
    if (izquierda < n && arr[izquierda] > arr[masGrande]) masGrande = izquierda;
    if (derecha < n && arr[derecha] > arr[masGrande]) masGrande = derecha;
    if (masGrande !== i) {
        [arr[i], arr[masGrande]] = [arr[masGrande], arr[i]];
        this.heapify(arr, n, masGrande);
    }
  }
  private heapsort_internal(arr: number[]) {
    let n = arr.length;
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        this.heapify(arr, n, i);
    }
    for (let i = n - 1; i > 0; i--) {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        this.heapify(arr, i, 0);
    }
  }


  private shellSort(arr: number[]): number[] {
    let size = arr.length;
    let gapsize = Math.floor(size / 2);
    while (gapsize > 0) {
        for (let j = gapsize; j < size; j++) {
            let temp = arr[j];
            let k = j;
            while (k >= gapsize && arr[k - gapsize] > temp) {
                arr[k] = arr[k - gapsize];
                k -= gapsize;
            }
            arr[k] = temp;
        }
        gapsize = Math.floor(gapsize / 2);
    }
    return arr;
  }

 private bucketSort(arr: number[]): number[] {
  if (arr.length === 0) {
    return arr;
  }

  let min = arr[0];
  let max = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] < min) min = arr[i];
    if (arr[i] > max) max = arr[i];
  }

  if (min === max) {
    return arr;
  }

  const s = arr.length;
  const bucketCount = s; 
  const bucketArr: number[][] = Array.from({ length: bucketCount }, () => []);
  const range = max - min;

  for (let j of arr) { 
      const bi = Math.floor((bucketCount - 1) * (j - min) / range);
      bucketArr[bi].push(j); 
  }

  for (let bukt of bucketArr) { 
      this.insertionSortForBucket(bukt); 
  }

  let idx = 0; 
  for (let bukt of bucketArr) { 
      for (let j of bukt) { 
          arr[idx] = j; 
          idx += 1; 
      }
  }
  return arr;
}
  private insertionSortForBucket(bukt: number[]) {
  for (let j = 1; j < bukt.length; j++) { 
      let val = bukt[j]; 
      let k = j - 1; 
      while (k >= 0 && bukt[k] > val) {
          bukt[k + 1] = bukt[k]; 
          k -= 1; 
      }
      bukt[k + 1] = val; 
  }
}

}