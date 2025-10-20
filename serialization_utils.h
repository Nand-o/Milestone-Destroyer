// serialization_utils.hpp
#ifndef SERIALIZATION_UTILS_HPP
#define SERIALIZATION_UTILS_HPP

#include <fstream>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream> // Untuk pesan error/sukses

// Fungsi untuk menyimpan objek ke file (tanpa try-catch)
template <typename T>
bool saveData(const T& data, const std::string& filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error: Tidak dapat membuka file '" << filename << "' untuk ditulis." << std::endl;
        return false;
    }
    boost::archive::text_oarchive oa(ofs);
    oa << data;
    if (!ofs.good()) {
        std::cerr << "Error: Terjadi masalah saat menulis ke file '" << filename << "'." << std::endl;
        return false;
    }
    std::cout << "Data berhasil disimpan ke '" << filename << "'." << std::endl;
    return true;
}

// Fungsi untuk memuat objek dari file (tanpa try-catch)
template <typename T>
bool loadData(T& data, const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Info: File '" << filename << "' tidak ditemukan atau tidak bisa dibuka." << std::endl;
        return false;
    }
    boost::archive::text_iarchive ia(ifs);
    ia >> data;
    if (!ifs.good() && !ifs.eof()) {
        std::cerr << "Error: Terjadi masalah saat membaca dari file '" << filename << "'. File mungkin rusak." << std::endl;
        return false;
    }
    std::cout << "Data berhasil dimuat dari '" << filename << "'." << std::endl;
    return true;
}

#endif // SERIALIZATION_UTILS_HPP
