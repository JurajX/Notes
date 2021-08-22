--------------------------------------------SCIKIT-LEARN-
---------------------------------------------------------

import sklearn as skl

                          -----SPARSE MATRIX-----

SM                                        # Effectively encodes array of 'basis vectors'.
SM.toarray()                              # Converts SM to an array of 'basis vectors'.

                          -----MODULES-----

                               --------skl.datasets (module)

fetch_mldata('MNIST original')            # Downloads MNIST data, data_home= directory where to save it.

iris = datasets.load_iris()               # Downloads iris dataset, contains 150 iris flowers.

make_moons                                # Returns a 2D array with coordinates and 1D binary array with categories.


                               --------skl.externals (module)

joblib.dump(my_model, 'my_model.pkl')     # Saves model.
joblib.load('my_model.pkl')               # Returns the saved model.



                               --------skl.preprocessing (module)

imp = Imputer(strategy='median')          # Used for replacing NaN's (by median <-strategy).
statistics_                               # ... attribute: eturns an array of computed values (e.g. medians of each column).
fit, transform, fit_transform

L_encdr = LabelEncoder()                  # Used for encoding string categories to integer ones.
fit, transform, fit_transform             # ... methods: omputes the encoder, returns an array of numerical categories.
classes_                                  # ... attribute: returns array of classes in the encoder.

OH_encdr = OneHotEncoder()                # Used for encoding integer categories to sparse matrix (basis vectors).
fit_transform, fit, transform

LB_encdr = LabelBinarizer()               # Used for encoding string categories to sparse matrix (basis vectors).
    sparse_output=True                    # ... parameter: transform will return sparse matrix.
fit_transform, fit, transform

StandardScaler                            # Feature scaling, substracts mean and divides by variance.
MinMaxScaler                              # Feature scaling in [0,1], substracts min value and divides by (max-min).

poly_features = PolynomialFeatures()      # Constructs the transformer for polynomial features.
    degree=, include_bias=                # ... parameters: degree of polynomial features, bias term.
fit_transform, fit, transform             # ... methods



                               --------skl.decomposition (module)

pca = PCA()                               # Principal component (PC) transformer, takes care of centering the data.
    n_components                          # ... parameter: # of PC preserved, if in (0,1) then it indicates preserved variance.
    svd_solver                            # ... parameter: if 'randomized' then it performes randomized PCA, faster for d<<n.
fit_transform(),fit,transform             # ... method: classic transformers.
inverse_transform()                       # ... method: transforms reduced data back to the original form (some info lost).
components_                               # ... attribute: contains the pca components as horizontal vectors.
explained_variance_ratio_                 # ... attribute: returns variences of the first n-1 PCs.

inc_pca = IncrementalPCA()                # The same as PCA but batches of data can be used for fitting.
    n_components, batch_size              # ... parameters
partial_fit                               # ... method: fits the data on batches.

ker_pca = KernelPCA()                     # Maps the space to an inf-dim space (kernel trick) and then performs PCA.
    n_components, kernel, gamma           # ... parameters
    fit_inverse_transform                 # ... parameter: if true it makes possible to use inverse_transform() method.



                               --------skl.manifold (module)

lle = LocallyLinearEmbedding()            # Maps pts to a lower dim space, s.t. linearity is locally partially preserved.
    n_components, n_neighbors             # ... parameters: dim. of target space, # of nbhs taken into account.



                               --------skl.base (module)

cloned_mdl = clone(ML_model)              # Clones the model, used for implementing cross-validation.


# Create own transfomer
from sklearn.base import BaseEstimator, TransformerMixin

rooms_ix, bedrooms_ix, population_ix, household_ix = 3, 4, 5, 6
class CombinedAttributesAdder(BaseEstimator, TransformerMixin):
    def __init__(self, add_bedrooms_per_room = True):
        self.add_bedrooms_per_room = add_bedrooms_per_room
    def fit(self, X, y=None):
        return self
    def transform(self, X, y=None):
        rooms_per_household = X[:, rooms_ix] / X[:, household_ix]
        population_per_household = X[:, population_ix] / X[:, household_ix]
        if self.add_bedrooms_per_room:
            bedrooms_per_room = X[:, bedrooms_ix] / X[:, rooms_ix]
            return np.c_[X, rooms_per_household, population_per_household, bedrooms_per_room]
        else:
            return np.c_[X, rooms_per_household, population_per_household]



                               --------skl.pipeline (module)

# Pipelines are used to do all the transformations in one go.

from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler

num_pipeline = Pipeline([                 # All but the last estimators must be transformers
    ('imputer',Imputer(strategy='median')),
    ('std_scaler', StandardScaler())
])
data_transf = num_pipeline.fit_transform(data)



# In case there are two separate pipelines on two subsets of data.
from sklearn.pipeline import FeatureUnion

cols_for_pipe1 = list(data.columns_for_pipe1)
cols_for_pipe2 = list(data.columns_for_pipe2)

# Construction of the pipeline1.
pipe1 = Pipeline([('selector', DataFrameSelector(cols_for_pipe1)), ...])
# Construction of the pipeline1.
pipe2 = Pipeline([('selector', DataFrameSelector(cols_for_pipe2)), ...])
full_pipe = FeatureUnion(transformer_list=[
    ('pipeline1', pipe1),
    ('pipeline2', pipe2),])

full_pipe.fit(data)
transform, fit_transform



                               --------skl.model_selection (module)

# Splits data into train and test sets.
train, test = train_test_split(data, test_size=0.2, random_state=42)



# Stratified split of data.
split = StratifiedShuffleSplit(n_splits=1, test_size=0.2, random_state=42)

for train_idx, test_idx in split.split(data, data["strat_cat"]):
    strat_train_set = data.loc[train_index]
    strat_test_set = data.loc[test_index]



# StratifiedKFold performs stratifies sampling of data into training and test subsets. Use for performing cross_val_score() with more control. Usually goes with clone to clone the ML_model.
skfolds = StratifiedKFold(n_splits=2, random_state=42)
for train_index, test_index in skfolds.split(data, labels)


# Splits training set into N subsets, trains N times on N-1 subsets and evaluates on Nth (each time different) subset; returns the evaluation score for each test fold. Algorithm expects utility function, not a cost function.
cross_val_score(ML_model, data, labels, scoring=, cv=N)
    scoring='neg_mean_squared_error'      # ... parameter: negative mean squared error.
    scoring='accuracy'                    # ... parameter: divides true positives by number of instances.



# Splits training set into N subsets, trains N times on N-1 subsets and evaluates on Nth (each time different) subset; returns a clean predictions made on each test fold.
cross_val_predict(ML_model, data, labels, cv=N)
    method='decision_function'            # ... parameter: returns a clean decision function instead of a prediction.
    method='predict_proba'                # ... parameter: returns a clean probability prediction.



# GridSearchCV tries many parameters to find the best possible model. In the model you don't specify parameters you are grid-searching through.
param_grid = [
    {'n_estimators': [3, 10, 30], 'max_features': [2,4,6,8]},
    {'bootstrap': [False], 'n_estimators': [3,10], 'max_features': [2,3,4]},]

model = MY_MODEL()
grid_search = GridSearchCV(model, param_grid, cv=5, scoring='neg_mean_squared_error')
grid_search.fit(data, labels)
grid_search.best_estimator_

# Printing the evaluation scores
cv_res = grid_search.cv_results_
for mean_score, params in zip(cv_res['mean_test_score'], cv_res['params']):
    print(np.sqrt(-mean_score), params)

# Print importance of features.
grid_search.best_estimator_.feature_importances_
# Print the best parameters.
grid_search.best_params_


# RandomizedSearchCV; same as above but tries parameters randomly.
random_search = RandomizedSearchCV(...)



                               --------skl.metrics (module)

mean_squared_error(lbls, pred_lbls)       # Returns the mean square error between A and B.
precision_score(lbls, pred_lbls)
recall_score(lbls, pred_lbls)
accuracy_score(lbls, pred_lbls)           # Returns the accuracy score.
f1_score(lbls, pred_lbls)
confusion_matrix(lbls, pred_lbls)         # Returns the confusion matrix.

precision_recall_curve(lbls, pred_socres) # Returns precisions, recalls and tresholds (with obvious dependence).
roc_curve(labels, pred_scores)            # Returns false positive rate, true positive rate (recall), and tresholds.
roc_auc_score(labels, pred_socres)        # Computes the area below the TPR_vs_FPR graph (ROC AUC).



                               --------skl.linear_model (module)

lin_reg = LinearRegression()              # Linear regretion (solves the normal equation), no scaling needed.
fit, predict                              # ... methods: fits the data, returns a vector of predicted values.
intercept_                                # ... atributte: returns the absolute coefficient.
coef_                                     # ... attribute: returns the coefficient of data.

sgd_reg = SGDRegressor()                  # Stochastic gradient descent regressor, scaling required.
    n_iter=, eta0=                        # ... parameter: number of iterantions, start learning rate.
    penalty='l2'                          # ... parameter: regularization term used l2-norm.
    alpha='0.0001'                        # ... parameter: regularization constant, and default value.
    warm_start=True                       # ... parameter: fitting continues from the last known state.
fit, predict                              # ... methods: fits the data, returns a vector of predicted values.
intercept_, coef_                         # ... attributes

ridge_reg = Ridge()                       # Regularized linear regression, no scaling needed.
    alpha=,solver='cholesky'              # ... parameters: regularization constant, matrix factorization technique.
fit, predict

lasso_reg = Lasso(alpha=)                 # Least absolute shrinkage and selection operator regression, with l1 regularization.

elastic_net = ElasticNet()                # Trade-off between Ridge and Lasso regs, it has both terms, no scaling needed.
    alpha=, l1_ratio=                     # ... parameters: reg. const., l1_ratio* l1-norm + (1-l1_ratio)/2 * l2-norm.

log_reg = LogisticRegression()            # Logistic regression, default multiclass is one-vs-all.
    penalty=, C=                          # ... parameters: regularization term (l1, l2), reg. constant (inverse of alpha).

softmax_reg = LogisticRegression(         # Sets the logistic regression into a softmax regression instead of one-vs-all.
    multi_class="multinomial",
    solver="lbfgs", C=10)

sgd_clf = SGDClassifier(random_state=42)  # Stochastic gradient descent classifier, scaling required.
fit, predict                              # ... methods: for predictions the treshold used is 0, and can't be changed.
decision_function()                       # ... method: returns a vector of scores, one can set the treshold manualy.
classes_                                  # ... attribute: returns classes of the classifier.

per_clf = Perceptron(random_state=42)     # Perceptron (equivalent to SGDClf loss='perceptron',
                                          #             learning_rate='constant', eta0=1, penalty=None).

                               --------skl.tree (module)

tree_reg = DecisionTreeRegressor()        # DecisionTreeRegressor, sensitive to orientation, no scaling needed.
    max_depth, max_leaf_nodes             # ... parameters: max depth limit, max number of leafs.
    max_features                          # ... parameter: max number of features evaluated for splitting each node.
    min_samples_leaf, min_samples_split   # ... parameters: min number of samples in a leaf/ in a node before splitting.
    min_weight_fraction_leaf              # ... parameter: same as min_samples_leaf, espressed as a fraction of total number.
fit, predict

tree_clf = DecisionTreeClassifier()       # DecisionTreeClassifier, sensitive to orientation, no scaling needed.


                               --------skl.multiclass (module)

OneVsOneClassifier(ML_clf())              # Constructs a classifier forsed to do OvO classification.
OneVsRestClassifier(ML_clf())             # Constructs a classifier forsed to do OvR classification.

knn_clf = KNeighborsClassifier()
fit



                               --------skl.svm (module)

linear_svc = LinearSVC()                  # Linear support vector machines classifier, scalling needed!
    C, loss, penalty,                     # reg. parameter, loss function e.g. 'hinge', penalty e.g. l1 or l2.

svm_clf = SVC()                           # Support vector machines classifier with kernel, scalling needed!
    kernel, C, tol                        # ... parameters: kernel, reg. term, tolerance term (sets precision).
    degree, coef0                         # ... parameters (kernel='poly'): deg, high vs. low degree polynomial significance.
    gamma                                 # ... parameter (kernel='rbf'): exp(- gamma (x-y)^2).
    probability                           # ... parameter: if set to True, the classifier has predict_proba() method

linear_svr = LinearSVR()                  # Linear support vector machines regression.
    epsilon                               # ... parameter: width of the margin.

svr_reg = SVR()                           # Support vector machines regression with kernel
    kernel, degree, C, epsilon            # ... parameters.


                               --------skl.ensemble (module)

voting_clf = VotingClassifier()           # Voting classifier
    estimators=[('clf1', clf1),...]       # ... parameter: put in all the clasifiers (already defined).
    voting='hard'/'soft'                  # ... parameter: determined voting, if 'soft' all clfs have to have predict_proba.

bag_clf = BaggingClassifier()             # This trains the same classifier many times and then performs soft voting.
    ML_clf, n_estimators, max_samples     # ... parameters: clf, # of trained clf, train set size (or max_samples*#ofexmpls).
    bootstrap, n_jobs                     # ... parameters: True/False for bagging/pasting, # of cores in use (-1 for all).
    oob_score                             # ... parameter: performs evaluation of each trained clf on umpicked instances.
    max_features, bootstrap_features      # ... parameters: for sampling features similar to max_samples and bootstrap.
bag_clf.oob_score_/oob_decision_function  # ... method: returns oob_score, oob class probability on instances of train set.

rf_clf = RandomForestClassifier()         # Ensemble of decision trees traind via bagging or pasting method.
    random_state, n_estimators            # ... parameters: rand. state, number of decision trees trained
    max_leaf_nodes, n_jobs                # ... parameters: max number of leafs in a tree, number of cores in use
feature_importances_                      # ... attribute: based on the fact that unimportant features appear close to leaves.

erf_clf = ExtraTreesClassifier()          # Same as RandomForestClassifier, but with extra randomness, API is the same.

ada_clf = AdaBoostClassifier()            # Each consecuteive clf pays more attention to the misclassified training data.
    ML_clf, n_estimators, larning_rate    # ... parameters: (3rd) missclassified instance weight boosting.
    algorithm                             # ... parameters: use SAMME.R for clfs with predict_proba().

gbt_clf = GradientBoostingClassifier()    # Trains a sequence of decision trees, new predictors fit the residual errors of old.
    max_depth, min_samples_leaf
    n_estimators, learning_rate

bag_reg = BaggingRegressor()
rf_reg = RandomForestRegressor()
erf_reg = ExtraTreesRegressor()
ada_reg = AdaBoostRegressor()
gbt_reg = GradientBoostingRegressor()