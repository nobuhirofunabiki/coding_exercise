list = [1 5 7];

for iAgents = 1:10
    for iList = 1:length(list)
        if (iAgents == list(iList))
            disp(iAgents);
        end
    end
end

% 'ismember' function
for jAgents = 1:10
    hoge = ismember(jAgents, list)
end
