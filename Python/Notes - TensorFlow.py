--------------------------------------------TensorFlow-
-------------------------------------------------------


import tensorflow as tf

                          -----GRAPH EVALUATION-----

# Evaluate the graph and print result.
sess = tf.Session()                         # Starts a tf session, used for evaluation.
sess.run(x.initializer)                     # Initializes variable x.
result = sess.run(f)                        # Runs a defined function f, e.g. f=x**2.
sess.close()                                # Closes the session, frees up resources.
print(result)                               # Prints result of f.


# Another version how to evaluate a graph
with tf.Session() as sess:
    x.initializer.run()
    result = f.eval()
print(result)

sess.run([list])                            # Evaluates all the nodes in the list, can also be a single node.


InteractiveSession()                        # A TensorFlow Session for use in interactive contexts, such as a shell.
# Example.
sess = tf.InteractiveSession()              # Interactive session sets itself as a default session.
init.run()
result = f.eval()
sess.close()                                # Interactive session has to be closed manualy.


global_variables_initializer()              # Returns an Op that initializes global variables.
# Example.
init = tf.global_variables_initializer()    # Prepare an init node.
with tf.Session() as sess:
    init.run()                              # Actually initialize all the variables.



                          -----DEFAULT GRAPH-----

# Nodes are automatically added to the default graphs.
graph = tf.Graph()
with graph.as_default():                    # Sets the new graph as defaults, only for the with block.
    x2 = tf.Variable(2)                     # Adds the note to the default graph.
x2.graph is graph                           # Returns True.
x2.graph is tf.get_default_graph()          # Returns False.


tf.get_default_graph()                      # Returns the default graph.
tf.reset_default_graph()                    # Resets the default graph.

<node>.graph                                # Returns the graph associated with the node.
<graph>.as_default()                        # Returns a context mngr. that makes the graph default. Use with with statement.



--------------------------------------------tf

Graph()                                     # Creates a new graph.


name_scope()                                # Returns a context manager for use when defining a Python op. (Use with with/as.)
    name, default_name=None, values=None

variable_scope()                            # Returns a context manager for defining ops that creates variables (layers).
    name_or_scope, default_name=None, values=None, initializer=None, regularizer=None, caching_devce=None,
    partitioner=None, custom_getter=None, reuse=None, dtype=None, use_resources=None



                          -----Data types-----

float32,64; int8,16,32,64; uint8,16;        
complex64,128; qint8,32; quint8;
string; bool;


                          -----Creating tensors-----

constant()                                  # Creates a constant tensor, no initialization needed.
    value, dtype=None, shape=None, name='Const', verify_shape=False

Variable()                                  # A variable maintains state in the graph across calls to run().
    initial_value=None, trainable=True, collections=None, validate_shape=True, caching_device=None,
    name=None, variable_def=None, dtype=None, expected_shape=None, import_scope=None, constraint=None
    .shape, .get_shape()                    # Returns shape of a Variable.
get_variable()                              # Gets an existing variable with these parameters or creates a new one.
    name, shape=None, dtype=None, initializer=None, regularizer=None, trainable=True, collections=None,
    caching_device=None, partitioner=None, validate_shape=True, use_resource=None, custom_getter=None

placeholder()                               # Inserts a placeholder for a tensor that will be always fed.
    dtype, shape=None, name=None

placeholder_with_default()                  # A placeholder op that passes through input when its output is not fed.
    input, shape, name=None

fill()                                      # This operation creates a tensor of shape dims and fills it with value.
    shape, value, name=None

zeros(), ones()                             # Creates a tensor with all elements set to zero/one.
    shape, dtype=tf.float32, name=None

zeros_like(), ones_like()                   # Creates a same tensor as tensor with all elements set to zero/one.
    tensor, dtype=None, name=None, optimize=True

random_uniform()                            # Outputs random values from a uniform distribution.
    shape, minval=0, maxval=None, dtype=tf.float32, seed=None, name=None

random_normal()                             # Outputs random values from a normal distribution.
    shape, mean=0.0, stdev=1.0, dtype=tf.float32, seed=None, name=None

truncated_normal()                          # Outputs random values from a truncated normal distribution.
    shape, mean=0.0, stddev=1.0, dtype=tf.float32, seed=None, name=None

lin_space()                                 # Generates a sequence of num evenly-spaced values beginning at start.
    start, stop, num, name=None

random_shuffle()                            # Randomly shoffles a tensor along its zeroth dimension.
    value, seed=None, name=None

multinomial()                               # Draws samples from a multinomial distribution.
    logits, num_samples, seed=None, name=None, output_dtype=None


                          -----FUNCTIONS-----
+, -, *, /, **, %, -                        # add, substract, multiply, divide, pow, mod, negative.
&, |, >, <, >=, <=, ~                       # logical_and, logical_or, greater, less, greater_equal, less_equal, logical_not.


py_func()                                   # Wraps a python function and uses it as a TensorFlow op.
    func, inp, Tout, stateful=True, name=None

cond()                                      # Return true_fn() if the predicate pred is true else false_fn().
    pred, true_fn=None, false_fn=None, strict=False, name=None, fn1=None, fn2=None

assign()                                    # Update 'ref' by assigning 'value' to it.
    ref, value, validate_shape=None, use_locking=None, name=None

cast()                                      # Casts a tensor to a new type.
    x, dtype, name=None


add()                                       # Returns x+y element-wise.
    x, y, name=None

add_n()                                     # Adds all input tensors element-wise.
    inputs, name=None

matrix_inverse()                            # Computes the inverse of one or more square invertible matrices or their adjoints.
    input, adjoint=None, name=None)

matrix_transpose()                          # Transposes last two dimensions of tensor a.
    a, name='matrix_transpose'

matmul()                                    # Multiplies matrix a by matrix b, producing a * b
    a, b, transpose_a=False, transpose_b=False, adjoint_a=False, adjoint_b=False,
    a_is_sparse=False, b_is_sparse=False, name=None

trace()                                     # Compute the trace of a tensor x.
    x, name=None

square()                                    # Computes square of x element-wise.
    x, name=None

sqrt()                                      # Computes square-root of x element-wise.
    x, name=None

reduce_mean()                               # Computes the mean of elements across dimensions of a tensor.
    input_tensor, axis=None, keep_dims=False, name=None, reduction_indices=None

reduce_max(), reduce_min()                  # Computes the maximum/minimum of elements across dimensions of a tensor.
    input_tensor, axis=None, keep_dims=False, name=None, reduction_indices=None

equal()                                     # Returns the truth (boolean) value of (x == y) element-wise.
    x, y, name=None


transpose()                                 # Transposes a. Permutes the dimensions according to perm.
    a, perm=None, name='transpose'

stack(
    values, axis=0, name='stack'

unstack()                                   # Unpacks the given dimension of a rank-R tensor into rank-(R-1) tensors.
    value, num=None, axis=0, name='unstack'

expand_dims()                               # Inserts a dimension of 1 into a tensor's shape.
    input, axis=None, name=None, dim=None

squeeze()                                   # Removes dimensions of size 1 from the shape of a tensor.
    input, axis=None, name=None, squeeze_dims=None

gradients()                                 # Constructs partial derivatives of sum of ys w.r.t. x in xs.
    ys, xs, grad_ys=None, name='gradients',
    colocate_gradients_with_ops=False,
    gate_gradients=False, aggregation_method=None

scan()                                      # Scan on the list of tensors unpacked from elems on dimension 0.
    fn, elems, initializer=None, parallel_iterations=10,
    back_prop=True, swap_memory=False, infer_shape=True, name=None


--------------------------------------------tf.train

optimizer = GradientDescentOptimizer()      # Optimizer that implements the gradient descent algorithm.
    learning_rate, use_locking=False, name='GradientDescent'
optimizer.minimize()                        # Add operations to minimize loss by updating var_list.
    loss, global_step=None, var_list=None, aggregation_method=None, grad_loss=None


Saver()                                     # Saves and restores variables.
    var_list=None, reshape=False, sharded=False, max_to_keep=5, keep_checkpoint_every_n_hours=10000.0,
    name=None, restore_sequentially=False, saver_def=None, builder=None, defer_build=False, allow_empty=False,
    write_version=tf.train.SaverDef.V2, pad_step_number=False, save_relative_paths=False, filename=None
    .restore()                              # Restores previously saved variables.
        sess, save_path
    .save()                                 # Saves variables.
        sess, save_path, global_step=None, latest_filename=None,
        meta_graph_suffix='meta', write_meta_graph=True, write_state=True


--------------------------------------------tf.summary

scalar()                                    # Outputs a Summary protocol buffer containing a single scalar value.
    name, tensor, collections=None

FileWriter()                                # Writes Summary protocol buffers to event files.
    logdir, graph=None, max_queue=10, flush_secs=120, graph_def=None, filename_suffix=None
    .add_summary(summary, global_step=None) # ...adds a Summary protocol buffer to the event file.
    .close()                                # ...flushes the event file to disk and closes the file.


--------------------------------------------tf.nn

relu()                                      # Computes rectified linear: max(featrues, 0).
    featrues, name=None

elu()                                       # Computes exponential linear: exp(features) - 1 if <0, features otherwise.
    features, name=None

def leaky_relu(z, name=None):               # Definition of a leaky ReLU.
    return tf.maximum(0.01 * z, z, name=name)

sparse_softmax_cross_entropy_with_logits()  # Computes sparse softmax cross entropy between logits and labels.
    _sentinel=None, labels=None, logits=None, name=None

sigmoid_cross_entropy_with_logits()         # Computes sigmoid cross entropy given logits.
    _sentinel=None, labels=None, logits=None, name=None

in_top_k()                                  # Says whether the targets are in the top K predictions.
    predictions, targets, k, name=None

conv2d()                                    # 2D convolutional layer.
    input,                                  # Dimensions of input [batch, in_height, in_width, in_channels].
    filter,                                 # Dimensions of the filter [height, width, in_channels, out_channels].
    strides,                                # For the NHWC data_format strides must be [1, stride, stride, 1].
    padding,                                # "SAME" or "VALID"; SAME with stride=1 gives out dim equal to in dim.
    use_cudnn_on_gpu=True, data_format='NHWC', name=None

max_pool()                                  # Arguments are equivalent to conv2d().
    value, ksize, strides, padding, data_format='NHWC', name=None

dropout()                                   # Computes dropout for a floating point tensor x.
    x, keep_prob, noise_shape=None, seed=None, name=None

static_rnn()                                # Creates RNN specified by RNNCell cell; one layer per time step.
    cell, inputs, initial_state=None, dtype=None,
    sequence_length=None, scope=None

dynamic_rnn()                               # Creates RNN specified by RNNCell cell. Performs fully dynamic unrolling of inputs.
    cell, inputs, sequence_length=None, initial_state=None, dtype=None,
    parallel_iterations=None, swap_memory=False, time_major=False, scope=None

embedding_lookup()                          # Looks up ids in a list of embedding tensors.
    params, ids, partition_strategy='mod', name=None, validate_indices=True, max_norm=None


--------------------------------------------tf.contrib.learn

feature_columns = tf.contrib.learn.infer_real_valued_columns_from_input(X_train)

dnn_clf = tf.contrib.learn.DNNClassifier()
    hidden_units=[], n_classes=, feature_columns=feature_columns
    .fit()
        x=, y=, batch_size=, steps=
    .predict(X_test)
    .evaluate(X_test, y_test)


--------------------------------------------tf.contrib.layers

fully_connected()                           # Adds a fully connected layer.
    inputs, num_outputs, activation_fn=tf.nn.relu, normalizer_fn=None, normalizer_params=None,
    weights_initializer=initializers.xavier_initializer(), weights_regularizer=None,
    biases_initializer=tf.zeros_initializer(), biases_regularizer=None, reuse=None,
    variables_collections=None, outputs_collections=None, trainable=True, scope=None


--------------------------------------------tf.contrib.rnn

BasicRNNCell()                              # The most basic RNN cell.
    num_units, activation=tg.tanh

MultiRNNCell()                              # RNN cell composed sequentially of multiple simple cells, i.e. deep RNN.
    cells, state_is_tuple=True

OutputProjectionWrapper()                   # Operator adding an output projection to the given cell; not the best solution.
    cell, output_size, activation=None, reuse=None


--------------------------------------------TensorBoard-
--------------------------------------------------------

$ tensorboard --logdir tf_logs/             # Starts TensorBoard server pointed to the root log directory.

--------------------------------------------tf.summary

scalar()                                    # Outputs a Summary protocol buffer containing a single scalar value.
    name, tensor, collections=None, family=None

histogram()                                 # Outputs a Summary protocol buffer with a histogram.
    name, tensor, collections=None, family=None

merge_all()                                 # Merges all summaries collected in the default graph.
    key=tf.GraphKeys.SUMMARIES

FileWriter()                                # On construction the summary writer creates a new event file in logdir.
    logdir, graph=None, max_queue=10, flush_secs=120, graph_def=None, filename_suffix=None
    .add_summary()                          # Adds a Summary protocol buffer to the event file.
        summary, global_step=None
    .add_graph()                            # Adds a Graph to the event file.
        graph, global_step=None, graph_def=None

