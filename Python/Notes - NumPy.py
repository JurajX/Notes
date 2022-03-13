# ========== ========== ========== ========== NumPy
import numpy as np

# ========== NDARRAY ==========
# ----- Creating arrays
arr = np.ndarray(dims)
np.array(obj)                   # r: a multi-dim array of elements created out of obj.
np.asarray(obj)                 # ...as above but does not copy if obj is already an ndarray.

np.empty(shap)                  # r: an uninitialised array with dimensions equal to shap.
np.ndaray(shap)                 # ...as above, the above should be used.
np.zeros(shap), np.ones(shap)   # ...as above, but initialised with zeros/ones.
np.zeros_like(obj)              # r: an array of type obj initialised to zeros.
np.ones_like(obj)               # ...as above, but initialised to zeros
np.eye(N), np.identity(N)       # r: an identity NxN-dim matrix.
np.arange(dim)                  # r: an array-valued version the list-valued range(dim).
np.full(shap, fill, dtype)      # r: an array populateed with fill.

np.ix_([X, Y], [X, Y, Z])       # r: ( array([ [X],[Y] ]) , array([X,Y,X]) ), used for indexing arrays.
np.c_[arr1, arr2]               # r: concantinated array along the second axis.

# ----- Loading and saving arrays
np.save('name', arr)            # Saves the arr in the file 'name.npy' in current directory.
np.load('name.npy')             # r: an array from the file 'name.npy'.
np.savez('name', arr)           # Saves the arr in an zipped file; arrays can be given names, e.g. name=arr.
np.load('name.npz')             # r: a dict. 'arr_X' key for Xth stored array; if names, use 'name' as key.
np.savetxt('csv', arr)          # Saves arr to csv; delimiter can be specified.
np.loadtxt('csv')               # r: an array containing the csv file; delimiter can be specified.
np.memmap(FILE)                 # r: memorymap of arrays stored in binary file on disk as if they were in memory.

# ----- Merging/splitting arrays
np.concatenate([arr1, arr2], axis=X)    # r: a concatenate array along X axis.
np.append(arr1, arr2)                   # r: an appended array.
np.array_split(arr, N)                  # r: a list of N arrays.

# ----- Indexing
arr[-2:, 1:]                    # r: a refference to the slice of arr.
arr[i:j:k]                      # r: a slice of arr; i start idx, j istop idx, and k is step (possibly negative).
arr[-2:].copy()                 # r: a copy of the slice of arr.
arr[1, 2, ...], a[1][2][...]    # r: a slice/an element of arr.
arr[0] = X                      # assigns X to every element in the slice arr[0].
arr[[X, Y, X]]                  # r: a copy of a slices in specified order, (Xth, Yth, Xth).
arr[[X, Y], [X, Z]]             # r: a copy of slices corresponding to the coordinates (X,X) and (Y,Z).
arr[([[X], [Y]], [X, Y, X])]    # r: a copy of slices corresponding to [(X,X),(X,Y),(X,X)][(Y,X),(Y,Y),(Y,X)].
arr[np.ix_([X, Y], [X, Y, Z])]  # ...same as the line above.
arr[boolArr]                    # r: copy of slices corresponding to True in boolArr.

# ----- Methods
arr.shape                       # r: a tuple indicating the size of each dimension.
arr.dtype                       # r: a dtype object e.g. dtype('int64').
arr.astype(np.TYPE)             # r: a copy converted to TYPE (e.g. intX, floatX, complexX...).
arr.reshape(TUPLE)              # r: a view reshaped to TUPLE.
arr.ravel()                     # r: a flattened view.
arr.T                           # r: transposed view!
arr.transpose(TUPLE)            # r: transposed view, takes TUPLE of axis numbers to permute.
arr.swapaxes(X,Y)               # r: a view with swapped axes X and Y.
arr.sort(axis=X)                # r: sorts arr along X axis in place.
np.sort(arr)                    # r: a sorted copy.


# ========== FUNCTIONS ==========

# ----- Mathematics
import np.linalg as lalg

lalg.inv(Mat), lalg.pinv        # r: inverse of Mat.
lalg.qr(Mat)                    # r: QR decomposition; Mat=dot(Q,R); dot(Q,Q.T)=1, R is upper triangular.
lalg.svd(Mat_mn)                # r: svd decomposition.
lalg.diag                       # r: diagonal (or off-diag) elements of a square matrix, or maps vec to diag mat.
lalg.det                        # r: determinant.
lalg.eig(Mat)                   # r: eigenvalues and eigenvectors of Mat
lalg.solve(Mat,vec)             # r: solution to the equation Mat X = vec, for X.
lalg.lstsq(Mat,vec)             # r: the best approx solution to Mat X = vec, for X.

np.fill_diagonal(Mat, vec)      # Fills the diagonal of Mat with vec.

np.transpose(arr)               # r: transposed array, does not copy the array!
np.dot(arr1, arr2)              # r: dot product
arr1.dot(arr2)                  # ...as above.
np.trace(arr)                   # r: trace

np.around(arr, decimals=X)      # Rounds the values in arr to X decimal places.
np.meshgrid(arr, arr)           # r: 2D array (a grid) from 1D arrays.

np.abs(arr), fabs               # r: absolute value.
np.sign(arr)                    # r: sign of values.
np.log(arr)                     # r: log base e; use log10, log2, log1p for base 10, 2, and log(1+arr), respectively.
np.modf(arr)                    # r: integral part of arr in one array, and fractional part in other.
np.rint(arr)                    # r: elements to the nearest integer, preserving the dtype.
ceil, floor, exp, sqrt, sign    # r: corresponding functions.
+, -, *, /, **                  # element-wise operations.
np.power(arr1,arr2)             # r: elements of arr1 to the powers in arr2

add, subtract                   # r: corresponding functions.
multiply, divide                # r: corresponding functions.
floor_divide, mod               # r: corresponding functions.
sin, sinh, arcsin, arcsinh      # r: corresponding functions.
cos, cosh, arccos, arccosh      # r: corresponding functions.
tan, tanh, arctan, arctanh      # r: corresponding functions.

np.copysign(arr1, arr2)         # Copies sign of values of arr2 to values in arr1.
np.maximum(arr1, arr2)          # r: elementwise maximum, fmax ignores NaN's.
fmax, minimum, fmin             # r: corresponding functions.

# ----- Random numbers
np.random.seed                  # Sets the random seed
np.random.randn(shape)          # Generates an array (dim0, dim1,...) with random numbers of mean 0 and variance 1.
np.random.normal(size=(shape))  # Generates an array from the standard normal distribution.
np.random.permutation           # r: a random permutation of a sequence, or return a permuted range.
np.random.shuffle               # Randomly permutes a sequence in place.
np.random.rand(shape)           # Draws samples from a uniform distribution.
np.random.randint               # Draws random integers from a given low-to-high range.
np.random.randn                 # Draws samples from a normal distribution with mean 0 and standard deviation 1.
np.random.binomial              # Draws samples a binomial distribution.
np.random.normal                # Draws samples from a normal (Gaussian) distribution.
np.random.beta                  # Draws samples from a beta distribution.
np.random.chisquare             # Draws samples from a chi-square distribution.
np.random.gamma                 # Draws samples from a gamma distribution.
np.random.uniform               # Draws samples from a uniform [0, 1) distribution.
np.random.multinomial           # Draws samples from a multinomial distribution.

# ----- Logic
np.isnan(arr)                   # r: boolean array indicating whether each value is NaN (Not a Number).
isfinite, isinf                 # ... as above, but for infinite and finite queries.
np.logical_not(arr)             # r: truth value of not X, X is an element of arr; equivalent to -arr.
logical_or, logical_xor         # ... as above, but for or and xor.
greater, greater_equal          # r: boolean array, compares two arrays.
==, !=, &, |, ^, >, >=, <, <=   # Boolean operators: equals, inequals; same as np.greater, np.not_equal.
np.where(condition, [x, y])     # r: elements from x if True, from y if False; x, y are array-like, optional.
boolarr.any(), boolarr.all()    # Tests if any or all values in the array are True, returns boolean val accordingly.

# ----- 1D arrays & set logic
np.unique(arr)                  # r: the sorted, unique elements in arr.
np.intersect1d(arr1, arr2)      # r: the sorted, common elements in arr1 and arr2.
np.union1d(arr1, arr2)          # r: the sorted union of elements in arr1 and arr2.
np.in1d(arr1, arr2)             # r: a boolean array indicating whether an element of arr1 is contained in arr2.
np.setdiff1d(arr1, arr2)        # r: set difference.
np.setxor1d(arr1, arr2)         # r: set difference of set union and set intersection or arr1 and arr2.


# ========== STATISTICAL FUNCTIONS ==========
arr.mean(axis=X)                # r: a mean of the array along X, axis=1 takes rows, axis=0 takes culomns.
np.mean(arr, axis=X)            # ...as above.
arr.sum(axis=X)                 # r: a sum of the array along X, axis=1 summs rows, axis=0 summs culomns.
np.sum(arr, axis=X)             # ...as above.
arr.std, np.std()               # r: a standard deviation (with default denominator n).
arr.var, np.var                 # r: a standard variance (with default denominator n).
arr.cumsum(axis=X), np.cumsum   # r: a cumulative sum along X, for a matrix axis 1 cumsum rows.
arr.min, arr.max                # r: min, max.
arr.argmin, arr.argmax          # r: indices of (the first) min, max elements.
arr.cumprod                     # r: cumulative product.
