--------------------------------------------PANDAS

import pandas as pd
from pandas import Series, DataFrame

NaN                                      # Is the standard missing data sentinel used in pandas.


                          -----SERIES (Series)-----

Series                                   # Is a one-dim. ndarray with axis labels.
S=Series(LST)                            # Creates S from LST labeled by natural numbers.
S=Series(LST1, index=LST2)               # Creates S from LST1 labeled by values from LST2.
S=Series(DCT)                            # Creates S from a dictionary DCT.
S=Series(DCT, index=Arr)                 # Creates S indexed by Arr with values from DCT, not matching indices have NaN values.
'c' in S                                 # Retruns True of False depending on 'c' being an index.
S[IDX]                                   # Returns a slice of S. Behaves the same as np.Array.
S['a':'c']                               # Returns a slice of S, the endpoint 'c' is inclusive.
S[boolArr]                               # Returns only those index-value pairs for which index number correspond to True.
S == VAL                                 # Returns a boolean array indicating that value of S equals VAL.

                               ==> Operations on Series

It is possible to use NumPy functions, e.g. np.exp(obj2). AND METHODS???
S1 + S2,-,*,/                            # Adds values correspongind to the same index, non-overlapping indices get NaN.
(~S), (-S)                               # When S is boolean array, returns element-wise negation.

S1.add(S2, fill_value=0)                 # Adds values corresponding to the same index, missing indices are set to 0.
sub, div, mul                            # Substraction, division, multiplication.


                               ==> Series.methods

S.copy()                                 # Returns a copy of S.

S.values                                 # Retruns a ndarray of values.
S.index                                  # Returns a Index array (ndarray) of indices.
S.name = 'my_series'                     # Series object has a name attribute. (Visible when printed.)
S.index.name = 'my_index'                # Series index also has a name attribute. (Visible when printed.)
S.index = ['x','b','a']                  # Changes indexing of S.

S.fillna(VAL)                            # Replaces NaN in S by VAL.
S.fillna(method='ffill',limit=N)         # Replaces maximally N consequtive NaN values in S by forward/backward fill.  
S.dropna()                               # Returns Series without null values (NaN).
S.drop(IDX)                              # Returns a copy of S with values indexed by IDX dropped.

S.notnull()                              # Returns a boolean same-sized object indicating if the values are not null (NaN).
S.isnull()                               # Returns a boolean Series with indices from S and values True if S[index]=NaN.
S.isin(VALS)                             # Returns boolean Series depending on VALS being in S.
S.str.contains('substr')                 # Returns a boolean Series indicating 'substr' being in values of S.

S.sort_index()                           # Sorts S.index lexicographically, argument ascending=False reverses the order.
S.sort_values()                          # Sorts S.value lexicographically, argument ascending=False reverses the order.
S.unique()                               # Returns a Series of unique elements of S, in the order observed.

S.map(F)                                 # Transforms values of S by F, where F is either function of a dict-like object.
S.replace(X, Y)                          # Replaces values X (can be a list) by values Y (not necessarily a list).
S.replace(DICT)                          # Same as above.

S.reindex(IDX, fill_value=Val)           # Reindexes S with IDX, new indices get Val values (defalut NaN), returns a new copy.
method='ffill'/ 'bfill'                  # ...use forward/backward fill.

S.value_counts()                         # Returns containing value frequencies of S.
S.rank()                                 # Computes rank.

S.plot(kind='barh')                      # Plots the data in a horizontal bar chart.


                          -----DATAFRAME (DataFrame)-----

DF = DataFrame(Dict_of_lists)            # Creates DF, columns(rows) labeled by ordered list keys(position in the lists).
DF = DataFrame(DoL, columns=COL)         # Creates DF, with columns corresponding to COL list; NaN for unspecified columns.
DF = DataFrame(Dict_of_dicts)            # Creates DF, columns(rows) labeled by the outer(inner) dict keys.
DF = DataFrame(DoD, index=IDX)           # Creates DF, with rows corresponding to IDX list; NaN for unspecified rows.
Dict_of_Series                           # Same as DoD

DF['column'] /DF.column                  # Returns Series with 'column' values indexed the same as DF. Name is column label.
DF['column']['row']                      # Accesses the respective element of the data structure.
DF[:2] / DF[boolArray]                   # Returns the first two ROWS (not columns)/ ROWS corresponding to boolArray.

DF.loc['row']/iloc                       # Returns Series with 'row' values indexed by coulumns. Name is the row label.
DF.loc[ROWs, COLs]/iloc                  # Returns subset of DF corresponding to array-like ROWs and COLs objects.

DF['column'] = LIST                      # Creates or replaces 'column' values with LIST values; lengths must match.
DF['column'] = S                         # Creates of replaces all 'column' values with S values of the same index or NaN's.
del DF['column']                         # Deletes 'column' from DF.s

DF['column'].value_counts()              # Returns label-indexed Series, labels='column' values=number of occurrences.


                               ==> DataFrame methods

DF.index.name = 'my_row'                 # Sets DF index name attribute. (Visible when printed.)
DF.column.name = 'my_column'             # Sets DF column name attribute. (Visible when printed.)
DF.values                                # Returns ndarray of values, chooses dtype such that it can accomodate all values.
DF.columns                               # Returns a Index array (ndarray) of columns.
DF.index                                 # Returns a Index array (ndarray) of indices.
DF.T                                     # Returns transposed DF.
DF.reset_index()                         # Resets the index and adds the old one to a column 'index'; drop=True to prevent it.

DF.reindex(IDX1, columns=IDX2)           # Reindexes rows with IDX1 and columns with IDX2, returns a new copy.
DF.drop(IDX, axis=X)                     # Returns a copy of DF with IDX indexed values of axis X dropped, X=0 (rows).

DF.apply(F, axis=X)                      # Applies function F (def on 1D arrays) on each axis X of DF.
DF.applymap(F)                           # Applies function F (def on an element) element-wise.

DF.sort_index(axis=X)                    # Sorts axis X of DF.index lexicologically, ascending=False reverses the order.
DF.sort_values(by=COLS)                  # Sorts DF by values in COLS lexicologically,  ascending=False reverses the order.

DF.dropna(axis=X)                        # Drops every row/col containing NaN, X=0 (rows).
how='all'/ thresh=X                      # ...drops row/col that are all NaN; drops all rows with less non-NaN values than X.
DF.fillna({COL1:X, COL3:Y})              # Repleces NaN values in COL1 by X and in COL2 by Y, returns a new copy.
DF.fillna(method='ffill', limit=X)       # Replaces NaN using method 'ffill' or 'bfill', limit fills max X consecutive NaN's.

DF.describe()                            # Shows a summary of the numerical attributes.
DF.info()                                # Gives a quick description of the data.
DF.count()                               # Number of non-NaN values.
DF.head()                                # Displays first 5 rows of data.
DF.tail()                                # Returns last 5 rows of DF.
DF.hist(bins=N, figsize=(X,Y))           # Plots a histogram for each numerical attribute in dataframe.

DF.take(LST)                             # Returns only rows corresponding to LST.

DF.idxmax()/idxmin                       # Returns index values with max/min value.
DF.argmin()/argmax                       # Returns index locations (integers) with max/min value.
DF.sum(axis=X, skipna=False)             # Sums DF in the X axis; skipna=False: gives NaN if any val in the sum is NaN.
cumsum, cumprod, cummin, cummax,
quantile, mean, median, mad, var,
std, skew, kurt, diff, pct_change
corr, cov, corrwith, rank

DF.plot(kind=, x=, y=)                   # Plots data in DF.
s=,c=,alpha=,cmap=,label=                # ...size of the points, colour dependence, transparency of the points.

                               ==> Grouping DataFrames

grpd = DF[COL1].groupby(DF[COL2])        # Returns a special group-like object, can be printed using for loop (name, group in).
DF.groupby(COL2)[COL1]                   # Same as above, COLs can be lists of scalars!
axis=X                                   # ...argument of groupby().
prpd.mean()                              # Computes mean on the groups of COL1, grouped by COL2.
DF.groupedby(COL).mean()                 # Computes mean on all columns grouped by COL.
DF.groupby(COLs).size()                  # Computes sizes by groups grouped by COLs.

DF.groupby(Dict, axis=X)                 # Groups DF based on a dictionary, keys corresponds to columns/rows.
DF.groupby(FCT, axis=X)                  # Groups DF based on a function.



                          -----DF<->S OPERATIONS-----

NumPy ufuncs work fine with pandas
DF + S, -, *, /                          # Matches indices of S on DF's columns and +,-,*,/ from each row, same as np.array.
DF.add(S, axis=X), sub, div, mul         # Matches indices of S on DF's X axis and  +,-,*,/ from each row/col, same as np.array.


                          -----FUNCTIONS-----

pd.isnull(S)                             # Returns a boolean Series with indices from S and values True if S[index]=NaN.
pd.value_counts(OBJ.values, sort=False)  # Returns unsorted value coutns of OBJ

pd.cut(S, BUCs)                          # Classifyies S into buckets of BUCs (intervals or integer).
right=False, labels=LAB, precision=X     # Changes the interval, renames labels of buckets; sets precision (if BUCs is integer).
.labels, .levels                         # Methods returning labels of buckets and their levels.

pd.qcut(S, X)                            # Classifyies S into X, equal-sized buckets.

pd.get_dummies(DF['COL'])                # Returns a binary df with columns labeled by values of COL.
prefix='COL'                             # ...labels columns with a prefix

pd.plotting.scatter_matrix(DF)           # Plots each column of DF against every other.


                               ==> Loading and saving data

pd.read_csv('file', header=None)         # Loads csv, without header; names, index_col are params to set axes.
pd.read_table('file', sep='X')           # Loads X sep. data, default sep='\t' (tab); '\s+' for changing whitespace separation.
pd.read_fwf(), read_clipboard            # Loads data with fixed width cols (no delimiters) to a variable, read from clipboard.
nrows=N, na_values={key:val}             # ...reads only first N rows, replaces every 'val' in column 'key' by NaN.
chunksize=N                              # ...reads file in chuncks of N rows.

DF.to_csv('file.csv')                    # Writes DF into a csv file.
sys.stdout, sep, na_rep                  # ...writes it on the screen, delimiters setting, sets NaN values (default is empty).
index=False, header=False, cols=List     # ...omits row, column labels, writes out columns in the order of List.

DF.save('file')                          # Saves DF as file (pickle). May not be stable over time due to Library change.
pd.load('file')                          # Loads data from a file (pickle). May not be stable over time due to Library change.

H5 = pd.HDFStore('file.h5')              # Creates file.h5 and assigns it to H5file. Does not serves as a database!
H5['OBJ1'] = DF                          # Saves DF in H5 under the name OBJ1.
H5['OBJ2'] = S                           # Saves S in H5 under the name OBJ2.
H5['OBJ1']                               # Returns DF.

MSxls = pd.ExcelFile('file.xls')         # Assigns MS excel file to MSxls.
DF = MSxls.parse('Sheet1')               # Reads MS excel sheet into DF.


                               ==> Merging datasets

pd.merge(DF1, DF2, on=LoC)               # Merges DF1 and DF2 on a list of columns LoC (merging keys).
left_on=LoC1/right_on=LoC2               # ...use LoC1/LoC2 in DF1/DF2 as join keys.
how='inner'/outer/left/right             # ...inner takes intersection of vals in LoC; outer takes cartesian product.
suffixes=('_DF1','_DF2')                 # ...adds sufixes on columns with the same names.
left_index=True/right_index=True         # ...indicates that index of DF1/DF2 (or both) should be used as merging key(s).

DF1.join(DF2, how='outer')               # Merges DF1 and DF2 on indices.
on='key'                                 # ...merges indices of DF2 on 'key' column of DF1.
DF1.join([DF2, DF3,...])                 # Merges multiple DF's on indices.

pd.concat([S1, S2, S3], axis=X)          # Merges series along X axis, i.e. X=0/1, adds rows/columns of one to the other.
join='outer'/inner                       # ...takes cartesian product/intersection
join_axes=[LST]                          # ...axes to be used for joining
keys=LST                                 # ...creates hierarchical indes on the concatenation axis.

pd.concat([DF1, DF2])                    # Merges DF's with the same logic as above.
ignore_index=True                        # ...ignores the row indices.
axis, keys,

S1.combine_first(S2)                     # Merges series same as Series(np.where(pd.isnull(a), b, a)).
DF1.combine_first(DF2)                   # Same as above, but happens for each column.



                          -----INDEX-----

pd.Index                                 # Used for holding axis labels, is immutable, and array-like. 
IDX in DF.index                          # Returns boolean value depending on IDX being an index of DF.

DF.index=IDXs                            # Changes the original index with IDXs, modifies the original.
S.index=IDXs                             # Changes the original index with IDXs, modifies the original.

DF.rename(index=F, columns=G)            # Creates a new DF with index and columns changed by fcts/dicts F,G.
S.rename(index=F)                        # Creates a new S with index and columns changed by fcts/dicts F,G.
inplace=True                             # ...changes the original data.

DF.index.map(F)                          # Transforms indices of DF by F, where F is either function of a dict-like object.
S.index.map(F)                           # Transforms indices of S by F, where F is either function of a dict-like object.


                               ==> Index methods

I.append                                 # Concatenates with other Index objects, produces a new index.
I.diff, intersection, union              # Computes set difference, intersection, union.
I.isin(LST)                              # Computes bolean array indicating if entries of LST are in I.
I.delete/ insert, drop                   # Computes a new index by deleting/inserting i-th element, deleting passed values.
I.is_monotonic                           # Returns True if i<i+1 for all i.
I.is_unique, unique                      # Returns True if Index has not duplicates; computes the array of unique values of I.


                          -----MULTI-INDEXED DATA-----

S.unstack()                              # Converts multi-indexed Series S into a DataFrame.
DF.stack()                               # Converts DF into a multi-indexed Series.
DF.swaplevel('LVL1', 'LVL2')             # Swaps two index levels in DF.
DF.sortlevel(X)                          # Sorts indices in the level X.
DF.sum(level='LVL1', axis=X)             # Sums values in LVL1 of axis X.
DF.set_index(['COL1', 'COL2'])           # Creates a multi-indexed DF, indexed by COL's; to keep COL's in, pass drop=False.
DF.reset_index()                         # Does the opposite of set_index.

DF.stack()                               # Pivots columns into the rows, producing a multi-indexed Series; filteres NaN's.
S.unstack(X)                             # Rearranges (the X-th level of) a multi-indexed Series into a DataFrame.

DF.pivot('COL1', 'COL2', 'COL3')         # Makes COL1 index, COL2 column-index, fills the data with COL3 values.

DF.duplicated()                          # Returns a boolean series indicating whether each row is a duplicate of not.
DF.drop_duplicates(COLs)                 # Returns a DF where duplicated values in COLs are dropped; take_last=True.