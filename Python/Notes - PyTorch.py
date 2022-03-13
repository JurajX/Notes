# ========== ========== ========== ========== PyTorch
import torch

# ========== torch.Tensors package ==========
# (...) can be replaced by shape, np.array or Python iterable
# (3,2) e.g. shape of 3x2

# ----- CPU
torch.Tensor                    # class constructor uses global default dtype (torch.float32)

# Factory Functions
torch.tensor(...)               # infers dtype from data, copies the data
    dtype=torch.float32         # specifies the dtype of tensor
    requires_grad               # tensor tracks gradients, default False
torch.as_tensor(...)            # infers dtype from data, does not copy the data
torch.from_numpy(...)           # infers dtype from data, does not copy the data

torch.HalfTensor(...)           # 16-bit floating point
torch.FloatTensor(...)          # 32-bit floating point
torch.DoubleTensor(...)         # 64-bit floating point

torch.ByteTensor(...)           # 8-bit integer (unsigned)
torch.CharTensor(...)           # 8-bit integer (signed)
torch.ShortTensor(...)          # 16-bit integer (signed)
torch.IntTensor(...)            # 32-bit integer (signed)
torch.LongTensor(...)           # 64-bit integer (signed)

# ----- GPU
torch.cuda.Tensor(...)          # same as torch.cuda.FloatTensor
torch.cuda.TENSOR_NAME(...)     # GPU tensor

# ----- Operations on Tensors
t = torch.Tensor
t.OPERATION()                   # functional operation
t.OPERATION_()                  # in place operation

# element-wise operations, all these have the underscore counterparts
add, sub, mul, div              # +, -, *, /
eq, gl, lt, ge, le              # =, >, <, >=, <=
abs, neg, sqrt                  # absolute value, negative value

# reduction operations, all these have the underscore counterparts
zero()                          # creates tensor of the same shape with zeros
sum(dim, keepdim, dtype)        # sums the elements along dim
prod(dim, keepdim, dtype)       # multiplies...
mean(dim, keepdim)              # computes mean along dim
std(dim, unbiased, keepdim)     # computes standard deviation

# other operations, these don't have the underscore counterparts
bincount(weights, minlength)    # counts the frequency of each value

# ----- Methods of Tensors
t.item()                        # accesses the element of a scalar tensor
t.size()                        # returns the shape
t.numel()                       # returns the number of elements
t.reshape(shape)                # reshapes the tensor to shape
t.flatten(start_dym=X)          # flattens all dims starting from X-th
t.squeeze()                     # eliminates the dimensions of length 1
t.unsqueeze(dim=X)              # adds a dimension of length 1 as X-th dimension

t.max(dim, keepdim)             # max elem
t.argmax(dim, keepdim)          # (flattened) position of the max elem

# ----- Attributes of Tensors
t.is_leaf                       # True if t is leaf
t.requires_grad                 # True if t tracks gradients
t.grad                          # same shape tensor containing accumulated gradients
t.shape                         # returns the shape

# ----- torch.fcts
.cat((t1,t2), dim=X)            # concantinates tensor along X-th dim
.stack((t1,t2,...))             # stacks tensors along 0-th dimension

# ----- numpy bridge
t.numpy()                       # returns numpy tensor, CPU memory is shared



# ========== torch.nn package ==========
import torch.nn as nn           # all classes in nn inherite from nn.Module

# ----- Attributes of nn.Module
parameters()                    # returns iterator of all variables with requires_grad=True
zero_grad()                     # initialised all grads to zero
to(...)                         # moves all module params to CPU or GPU
state_dict()                    # returns dict with all module params
load_state_dict()               # initiialised the module with state dict

# ----- Layers
# convolution layers
nn.Conv1d(in_channels, out_channels, kernel_size, stride=1, padding=0, dilation=1, groups=1, bias=True)
nn.Conv2d(in_channels, out_channels, kernel_size, stride=1, padding=0, dilation=1, groups=1, bias=True)
nn.Conv3d(in_channels, out_channels, kernel_size, stride=1, padding=0, dilation=1, groups=1, bias=True)
nn.ConvTranspose1d(in_channels, out_channels, kernel_size, stride=1, padding=0, output_padding=0, groups=1, bias=True, dilation=1)
nn.ConvTranspose2d(in_channels, out_channels, kernel_size, stride=1, padding=0, output_padding=0, groups=1, bias=True, dilation=1)
nn.ConvTranspose3d(in_channels, out_channels, kernel_size, stride=1, padding=0, output_padding=0, groups=1, bias=True, dilation=1)
nn.Unfold(kernel_size, dilation=1, padding=0, stride=1)
nn.Fold(output_size, kernel_size, dilation=1, padding=0, stride=1)

# pooling layers

# padding layers

# linear layers
nn.Linear(in_features, out_features, bias=True)

# bilinear layers
nn.Bilinear(in1_features, in2_features, out_features, bias=True)

# dropout
nn.Dropout(p=0.5, inplace=False)

# ----- Distance

# ----- Losses
nn.MSELoss(size_average=None, reduce=None, reduction='elementwise_mean')
nn.BCELoss(weight=None, size_average=None, reduce=None, reduction='elementwise_mean')
nn.BCEWithLogitsLoss(weight=None, size_average=None, reduce=None, reduction='elementwise_mean', pos_weight=None)
nn.CrossEntropyLoss(weight=None, size_average=None, ignore_index=-100, reduce=None, reduction='elementwise_mean')
nn.NLLLoss(weight=None, size_average=None, ignore_index=-100, reduce=None, reduction='elementwise_mean')

loss.backward()                 # computes gradients


# ----- Custom layers/modules
class MyModule(nn.Module):
    def __init__(self, num_inputs, num_classes, dropout_prob=0.3):
        super(MyModule, self).__init__()
        self.pipe = nn.Sequential(
            nn.Linear(num_inputs, 5),
            nn.ReLU(),
            nn.Linear(5, num_classes),
            nn.Dropout(p=dropout_prob),
            nn.Softmax()
            )

    def forward(self, x):
        return self.pipe(x)


# ========== torch.optim package ==========
optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=0.9)
optimizer = optim.Adam([var1, var2], lr=0.0001)

Adam(params, lr=0.001, betas=(0.9, 0.999), eps=1e-08, weight_decay=0, amsgrad=False)
SGD(params, lr=0.01, momentum=0, dampening=0, weight_decay=0, nesterov=False)
RMSprop(params, lr=0.01, alpha=0.99, eps=1e-08, weight_decay=0, momentum=0, centered=False)
Adagrad(params, lr=0.01, lr_decay=0, weight_decay=0, initial_accumulator_value=0)

optimizer.step()            # performs grad descent (applies gradients)
optimizer.zero_grad()       # zeros gradients of all parameters passed to optimiser


# ========== torch.utils package ==========
.data.DataLoader(
    dataset, batch_size=1, shuffle=False, sampler=None, batch_sampler=None,
    num_workers=0, collate_fn=None, pin_memory=False,
    drop_last=False, timeout=0, worker_init_fn=None
)


# ========== torchvision package ==========
.datasets.FashionMNIST(root, train, transform, target_transform, download)
.utils.make_grid(tensor, nrow, padding, normalize, range, scale_each, pad_value)


# ========== TensorBoardX ==========
# from tensorboardX import SummaryWriter
writer = SummaryWriter()
writer.add_scalar(name, value, index)
writer.close()
