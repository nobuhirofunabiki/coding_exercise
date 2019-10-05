clear

% Save the name of the current branch in "git_branch_name"
command1 = ['git rev-parse --abbrev-ref HEAD'];
[s,git_branch_name] = system(command1);

% Save the name of the current commit hash in "git_hash_name"
command2 = ['git rev-parse HEAD'];
[s,git_hash_name] = system(command2);

% Save the status of the current commit as a txt file
DateString = datestr(datetime('now'));
fileID = fopen('git_status.txt','w');
fprintf(fileID,'%s\r', ['Time: ', DateString]);
fprintf(fileID,'%s', ['Branch name: ', git_branch_name]);
fprintf(fileID,'%s', ['Commit hash: ', git_hash_name]);
fclose(fileID);