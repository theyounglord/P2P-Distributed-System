cd build/macos
cmake ../..
make

./P2PFileSharing --env development



< ----------------- Client Side ------------------- >
< ------------------------------------------------- >
< ----------------- File Upload Process ------------------- >

1. User initiate File Upload Process
2. Look For Available Leechers with available storage
3. Ask the user to choose how much storage of each should be 
4. Create Hash of the file and then store this hash in the 
5. Create a chunk of the file and then store the chunk in the chunk assembly folder
6. Create a file lock mechanism for each chunk
7. Send the chunk to the leechers
8. Once the leecher gets the chunk, then the leecher will send the ack to the seeder
9. Once the seeder gets the ack from all the leechers, then the seeder will send the file to the tracker
- which will include the file name, file size, file hash, file chunks(what are the chunks of the file, means how many chunks are there), file leechers(who are currently downloading the file), file seeders(who are currently uploading the file)
10. Tracker will then update the file status and then send the ack to the seeder
11. Seeder will then send the ack to the user that the file is uploaded successfully
12. Once the file is uploaded successfully, then the user can download the file from the tracker

< ----------------- File Download Process ------------------- >

1. User initiate File Download Process using the tracker and then the tracker will send the file details to the user
2. User will then send the request to the tracker to download the file
3. Tracker will then send the file details to the user
4. User will then send the request to the seeder to download the file
5. Seeder will then send the file to the user
6. User will then send the ack to the seeder
7. Seeder will then send the ack to the tracker
8. Tracker will then send the ack to the user that the file is downloaded successfully




<!-- 4. Then Accordinly break the chunks of the current file into one chunk assembly folder of that file and then once the process is done
4. After that 

    - this process will include chunk naming, adding que adrress to each and then start looking for available leechers(client) and creating multiple tcp connction for each chunk to thier leechers

    - Before sending to each leechers ask for permission rights
    - Based on that create a file lock mechanism
    - Once the file is uploaded to the leecher, then the leecher will send the ack to the seeder
    - Once the seeder gets the ack from all the leechers, then the seeder will send the file to the tracker
    (which will include the file name, file size, file hash, file chunks, file leechers(who are currently downloading the file), file seeders(who are currently uploading the file))
    - Tracker will then update the file status and then send the ack to the seeder
    - Seeder will then send the ack to the user that the file is uploaded successfully

5. Once the file is uploaded successfully, then the user can download the file from the tracker -->