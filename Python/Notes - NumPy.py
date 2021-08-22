# --------------------------------------------NUMPY

import numpy as np

                          -----NDARRAY-----

ndaray                                   # Is a (usually fixed-size) multi-dim. container of items of the same type and size.
Array[-2:,1:]                            # Returns a refference to the slice of Array. Not for copying!
Arr[i:j:k]                               # Returns a slice of Arr; i start idx, j istop idx, and k is step (possibly negative).
Array[-2:].copy()                        # Returns a copy of the slice of Array. For copying!
Array[1,2,...]/Array[1][2][]...          # Retruns a slice/an element of Array.
Array[0] = X                             # Changes every number in the slice Array[0] to X.
Array[[5,-3,5]]                          # Retruns a copy of Array slices in a desired order (5th, 3rd from the end, 5th row).
Array[ [X,Y],[X,Z] ]                     # Returns 1D array corresponding to coordinates (X,X) and (Y,Z).
Array[( [ [X],[Y] ] , [X,Y,X] )]         # Returns a copy of slices corresponding to [(X,X),(X,Y),(X,X)][(Y,X),(Y,Y),(Y,X)].
Array[np.ix_([X,Y],[X,Y,Z])]             # Same as the line above.
Array[boolArray]                         # Returns copy of slices corresponding to True in boolArray.


                          -----NDARRAY METHODS-----

Array.shape                              # Returns a tuple indicating the size of each dimension.
Array.dtype                              # Returns a dtype object e.g. dtype('int64').
Array.astype(np.TYPE)                    # Converts Arrray to TYPE (e.g. intX, floatX, complexX...). Always makes a new copy.
Array.reshape(TUPLE)                     # Reshapes 1D arrray into an array specified by TUPLE (dim1, dim2, ...).
Array.reshape(-1,1)                      # Creates column vector, -1 means unspecified and is calculated from the other entry.
Array.ravel()                            # Returns a contiguous flattened array.

Array.T                                  # Returns transposed array, does not copy the array!
Array.transpose(TUPLE)                   # Returns transposed array, doesn not copy, takes TUPLE of axis numbers to permute.
Array.swapaxes(X,Y)                      # Swaps axes X and Y, e.g. X=0, Y=1 transposes 2D array.
Array.sort(axis=X)                       # Sorts Array along X axis (the array will be changed).
np.sort(Array)                           # Returns a sorted copy, does not change Array.


                          -----FUNCTIONS-----

                               #==> Creating arrays

np.array(SLO, dtype=np.float64)          # Converts SLO into np.array (ndarray). Nested SLO's go to multi-dim. arrays.
np.asarray(SLO)                          # As previous but doesn't copy if SLO is already an ndarray.
np.zeros((dim0,...))/np.ones/np.empty    # Creates a (dim0,...)-array of 0's, 1's or non-init values.
np.zeros_like(SLO)/np.ones_like/...      # Creates an array of 0's, 1's or non-init values of the same shape and type as SLO.
np.eye(N)/np.identity(N)                 # Creates a NxN-dim identity array.
np.arange(dim)                           # Creates an array-valued version the list-valued range(dim).
np.full(shape, fill_val, dtype)          # Creates an array and populates it with fill_val.

np.ix_([X,Y],[X,Y,Z])                    # Returns ( array([ [X],[Y] ]) , array([X,Y,X]) ), used for indexing arrays.
np.c_[Arr1, Arr2]                        # Returns concantinated array along the second axis.

                               ==> Loading and saving arrays

np.save('name', Array)                   # Saves Array in the file 'name.npy' in current directory.
np.load('name.npy')                      # Loads data from the file 'name.npy'.
np.savez('archiv.npz', a=Arr1, b=Arr2)   # Saves two arrays in an zipped file.
np.load('archiv.npz')                    # Returns dict-like object. _X['a'] returns Arr1.
np.loadtxt('csv.txt', delimiter=',')     # Loads a CSV file into the environment.
np.savetxt('csv.txt',Arr,delimiter=',')  # Saves Arr to csv.txt

np.memmap(FILE, dtype=, mode=, shape=)   # Manipulation of arrays stored in binary file on disk as if they were in memory.

                               ==> Merging/splitting arrays

np.concatenate([Arr1, Arr2], axis=X)     # Merges the arrays along X axis, i.e. X=0/1, adds rows/columns of one to the other.
np.append(Arr1, Arr2)                    # Appends Arr2 to the end of Arr1.

np.array_split(Arr, N)                   # Splits an array into N parts.


                               ==> Mathematics

np.linalg.inv(Mat)/np.linalg.pinv        # Computes inverse of matrix Mat.
np.linalg.qr(Mat)                        # Performs QR decomposition; Mat=dot(Q,R); dot(Q,Q.T)=1, R is upper triangular.
np.linalg.svd(Mat_mn)                    # Mat.mean=0, Mat_{mn}=U_{mm}S_{mn}V*_{nn}; U,V unitary; S "diag", * is Herm. con.
    np.dot(Mat, W_d)                     # Projection on hyperplane def. by first d principal components, i.e. W_d = V*[:, :d].
    np.dot(Mat_reduced, W_d.T)           # Inverse transformation to the original form, some information is lost.
np.linalg.diag                           # Returns diagonal (or off-diag) elements of a square matrix, or maps vec to diag mat.
np.linalg.det
np.linalg.eig(Mat)                       # Returns eigenvalues and eigenvectors of Mat
np.linalg.solve(Mat,vec)                 # Solves equation Mat X = vec, for X.
np.linalg.lstsq(Mat,vec)                 # Computes the best approx solution to Mat X = vec, for X.
np.fill_diagonal(Mat, vec)               # Fills the diagonal of Mat with vec.

np.transpose(Arr)                        # Returns transposed array, does not copy the array!
np.dot(Arr1, Arr2)/Arr1.dot(Arr2)        # Computes matrix multiplication of Arr1 and Arr2.
np.trace(Arr)

np.around(Arr, decimals=X)               # Rounds the values in Arr to X decimal places
np.meshgrid(1DArr,1DArr)                 # Returns 2D array of

np.abs(Arr)/fabs                         # Computes absolute value, use faster fabs for non-complex data.
np.sign(Arr)                             # Computes sign of values.
np.log(Arr)/ log10/log2/log1p            # Computes log base e/10/2 and log(1+Arr)
np.modf(Arr)                             # Returns integral part of Arr in one array, and fractional part in other.
np.rint(Arr)                             # Rounds elements to the nearest integer, preserving the dtype.
ceil/floor/exp/sqrt/sign/
+, -, *, /, **                           # Between equal-size arrays (or arrays and scalar) apply elementwise.
np.power(Arr1,Arr2)                      # Raises elements of Arr1 to the powers in Arr2.
add/subtract/multiply/divide/
floor_divide/mod

sin / sinh / arcsin / arcsinh
cos / cosh / arccos / arccosh
tan / tanh / arctan / arctanh

np.copysign(Arr1, Arr2)                  # Copies sign of values of Arr2 to values in Arr1.
np.maximum(Arr1, Arr2)/fmax              # Returns elementwise maximum, fmax ignores NaN's.
minimum, fmin


                               ==> Random numbers

np.random.randn(dim0, dim1,...)          # Generates an array (dim0, dim1,...) with random numbers of mean 0 and variance 1.
np.random.normal(size=(dim1,...))        # Generates an array from the standard normal distribution.
np.random.seed
np.random.permutation                    # Returns a random permutation of a sequence, or return a permuted range.
np.random.shuffle                        # Randomly permutes a sequence in place.
np.random.rand(dim0, dim1,...)           # Draws samples from a uniform distribution.
np.random.randint                        # Draws random integers from a given low-to-high range.
np.random.randn                          # Draws samples from a normal distribution with mean 0 and standard deviation 1.
np.random.binomial                       # Draws samples a binomial distribution.
np.random.normal                         # Draws samples from a normal (Gaussian) distribution.
np.random.beta                           # Draws samples from a beta distribution.
np.random.chisquare                      # Draws samples from a chi-square distribution.
np.random.gamma                          # Draws samples from a gamma distribution.
np.random.uniform                        # Draws samples from a uniform [0, 1) distribution.
np.random.multinomial(n, pvals, size)    # Draw samples from a multinomial distribution.


                               ==> Logic

np.isnan(Arr)                            # Returns boolean array indicating whether each value is NaN (Not a Number).
isfinite / isinf /
np.logical_not(Arr)                      # Computes truth value of not X, X is an element of Arr. Equivalent to -Arr.
logical_or, logical_xor
greater/greater_equal...                 # Returns boolean array, compares two arrays.
== != & |(or) ^(xor) > >= < <=           # Boolean operators: equals, inequals... Equivalen to np.greater/np.not_equal.
np.where(condition, [x,y])               # Returns elements from x if True, from y if False; x,y are array-like, optional.
boolArr.any()/boolArr.all()              # Tests if any/all values in the array are True, returns boolean val accordingly.


                               ==> 1D Arrays & set logic

np.unique(Arr)                           # Computes the sorted, unique elements in Arr.
np.intersect1d(Arr1, Arr2)               # Computes the sorted, common elements in Arr1 and Arr2.
np.union1d(Arr1, Arr2)                   # Computes the sorted union of elements in Arr1 and Arr2.
np.in1d(Arr1, Arr2)                      # Computes a boolean array indicating whether an element of Arr1 is contained in Arr2.
np.setdiff1d(Arr1, Arr2)                 # Computes set difference.
np.setxor1d(Arr1, Arr2)                  # Computes set difference of set union and set intersection or Arr1 and Arr2.



                          -----STATISTICAL METHODS/FUNCTIONS-----

Arr.mean(axis=X)/np.mean(Arr, axis=X)    # Returns a mean of the array along X, axis=1 takes rows, axis=0 takes culomns.
Arr.sum(axis=X)/np.sum(Arr, axis=X)      # Returns a sum of the array along X, axis=1 summs rows, axis=0 summs culomns.
keepdims=True                            # The reduced axes are left to be 1D, this results in correct broadcasting.
Arr.std/np.std(), Arr.var/np.var         # Retutns a standard deviation and variance (with default denominator n).
Arr.cumsum(axis=X)/np.cumsum()           # Returns a cumulative sum along X, for a matrix axis 1 cumsum rows.
min/max, argmin/argmax, cumprod          # Returns min/max, indices of (the first) min/max elements, cumulative product.
