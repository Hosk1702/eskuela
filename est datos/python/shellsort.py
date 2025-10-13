class Shellsort:
    @staticmethod
    def display(arr):
        for i in arr:
            print(i, end=" ")
        print()

    def sort(self, arr):
        size = len(arr)
        gapsize = size // 2

        while gapsize > 0:
            for j in range(gapsize, size):
                temp = arr[j]
                k = j

                while k >= gapsize and arr[k - gapsize] > temp:
                    arr[k] = arr[k - gapsize]
                    k -= gapsize

                arr[k] = temp
            gapsize = gapsize // 2
        return 0
    
if __name__ == "__main__":
    arr = [12, 34, 54, 2, 3]
    print("Arreglo antes del ordenamiento:")
    Shellsort.display(arr)
    obj = Shellsort()
    obj.sort(arr)
    print("Arreglo despues del ordenamiento:")
    Shellsort.display(arr)
