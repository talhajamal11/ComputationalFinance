
clear;
data=load('asset_returns.csv');
assets=83;
tR=0.03;
means=zeros(assets,1);
for ii=1:assets
means(ii)=mean(data(:,ii));
%result=sprintf('%0.9f\n',means(ii));
%fprintf(result)
end

covMat=cov(data);
e=ones(assets,1);

A=[covMat,-means,-e; -means',0,0;-e',0,0];
rh=[zeros(assets,1);-tR;-1];

sol=A\rh

x=ones(assets+2,1);
x=conjgrad(A, rh, x);

norm(sol-x)


%eigs(covMat,20,'sm')

%length(covMat)
