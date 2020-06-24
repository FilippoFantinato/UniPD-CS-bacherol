function [L, A] = fattorizzazione_LU(A)

n = size(A,1);
L = zeros(n,n);

for k = 1:n-1
    L(k,k) = 1;
    for i = k+1:n 
        L(i,k) = A(i,k) / A(k,k);
        
        for j = k:n
            A(i, j) = A(i,j)-L(i, k)*A(k,j);
        end
    end
end

L(n,n) = 1;

end
