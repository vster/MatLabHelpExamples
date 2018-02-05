%% Plane Rotations
%
% This example shows how to do plane rotations
% using Symbolic Math Toolbox(TM).
%
% Copyright 1993-2009 The MathWorks, Inc.

%%
% Create a symbolic variable named t.

t = sym('t')

%%
% Create a 2-by-2 matrix representing a plane rotation through an angle t.

G = [ cos(t) sin(t); -sin(t) cos(t)]

%%
% Compute the matrix product of G with itself.

G*G

%%
% This should represent a rotation through an angle of 2*t.
% Simplification using trigonometric identities is necessary.

ans = simplify(ans)

%%
% G is an orthogonal matrix; its transpose is its inverse.

G.'*G

ans = simplify(ans)

%%
% What are the eigenvalues of G?

e = eig(G)

%%
% Apply the simplification rules.

e = simplify(e)


displayEndOfDemoMessage(mfilename)
