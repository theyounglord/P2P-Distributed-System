#!/bin/zsh

# Root directory check
echo "Creating project folder structure in the current root directory..."

# Create core source code structure
mkdir -p src/{client,networking,file_transfer,serialization,security,database,api/v1,file_transfer,middleware,threads,utils}

# Create client-side folder structure
mkdir -p client_ui

# Create build, include, and lib directories
mkdir -p {build/macos,lib/macos,lib/common,include,tests,scripts,docs,env,config,db/{mongodb,postgresql}}

# Create core C++ files inside the src directories
touch src/main.cpp
touch src/config_manager.h

# Client-side application files
touch src/client/{cli_interface.cpp,client_file_manager.cpp,client_sync_manager.cpp,peer_connection_manager.cpp,client_config_manager.cpp}

# Networking-related files
touch src/networking/{tcp_connection.h,udp_connection.h,peer_discovery.h,network_manager.cpp,peer_tracker.cpp}

# File transfer files
touch src/file_transfer/{file_splitter.h,file_assembler.h,file_verifier.h,file_transfer_manager.cpp,file_chunk_manager.h}

# Serialization files
touch src/serialization/{protobuf_serialization.h,json_serialization.h,serialization_manager.cpp}

# Security files
touch src/security/{encryption_handler.h,decryption_handler.h,key_management.cpp}

# Database files
touch src/database/{postgresql_database.h,mongodb_database.h,database_manager.cpp}

# API structure for versioned APIs
mkdir -p src/api/v1/file
touch src/api/v1/file/{upload_file.h,download_file.h,delete_file.h,file_metadata.h}
touch src/api/v1/peer/{connect_peer.h,disconnect_peer.h,peer_list.h}
touch src/api/v1/security/{auth_middleware.h,login.h,logout.h}
touch src/api/v1/analytics/{activity_log.h,usage_stats.h}

# Middleware files
touch src/middleware/{auth_middleware.h,logging_middleware.h,request_validation.h,rate_limiter.h}

# Threading and concurrency files
touch src/threads/{thread_pool.h,worker_threads.h,thread_manager.cpp}

# Utility files
touch src/utils/{string_helpers.h,file_helpers.h,log_helpers.h}

# Create include headers for the project
touch include/{networking.h,file_transfer.h,api.h,database.h,security.h,middleware.h}

# Create environment files
touch env/.env.development env/.env.staging env/.env.production

# Create configuration files
touch config/{development_config.json,staging_config.json,production_config.json}

# MongoDB and PostgreSQL DB setup scripts
mkdir -p db/mongodb/{users,files}
touch db/mongodb/users/{create_collection.js,seed_data.js,migration_1.js}
touch db/mongodb/files/{create_collection.js,seed_data.js,migration_1.js}
mkdir -p db/postgresql/{users,files}
touch db/postgresql/users/{create_table.sql,seed_data.sql,migration_1.sql}
touch db/postgresql/files/{create_table.sql,seed_data.sql,migration_1.sql}

# Create documentation files
touch docs/architecture.md

# Create CMakeLists.txt
touch CMakeLists.txt

# Create build automation scripts
touch scripts/{build_macos.sh,deploy_macos.sh,common_build.sh}

# Create test files for the system
touch tests/{test_networking.cpp,test_file_transfer.cpp,test_security.cpp,test_database.cpp,test_middleware.cpp,test_client.cpp}

echo "Project structure created successfully."
